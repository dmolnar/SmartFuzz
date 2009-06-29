
## triage components for gensearch and zzuf 

# assumes $valgrind is defined

use XML::Simple; 
require 'liblimits.pl'; 
require 'libstackhash.pl'; 

sub process_memcheck
{
    # expect "filename" in @_[0]  
    $filename = @_[0]; 
    $xmlname = @_[0] . "-memcheck"; 
    $seqno = @_[1]; 
    $fuzztype = @_[2];     
    $uuid = @_[3]; 

    # XMLin can throw an exception for some Valgrind memcheck outputs!
    # Therefore wrap it in an eval{}, which will catch the exception. 
    $memcheck = eval{XMLin($xmlname)}; 

    # Check to see if we hit an exception.
    # if we hit an exception, the return value is undefined. 
    if (! defined $memcheck)
    {
	# We hit an exception. Print the error.
	print "XMLin error: $@ \n"; 

	# Now copy the malformed file to the "malformedxml" directory.
	# We will go through these by hand later. Not pretty but
	# there are few enough that we can deal with it for now. 
	# Create "malformedxml" directory if it does not yet exist. 
	if (! (-e "malformedxml"))
        {
	    system("mkdir malformedxml");
	}
	system("cp $xmlname ./malformedxml/$xmlname"); 
	return; 
    }
	
    # For some reason list comprehension isn't working the way
    # I expect it, but indexing does, so initialize the index here.
    $i = 0; 
    
    # Check that we have at least one error in parsed memcheck output.
    if (! (ref($memcheck->{error}) eq 'ARRAY'))
    {
 	return; 
    }

    # Loop prologue. Also flag that we found valgrind bugs. 
    $foundVGBugs = 1; 
    $error = $memcheck->{error}[$i]; 

    # Loop over errors, extract error kinds and stack hashes.
    while ($error->{kind})
    {
	$error = $memcheck->{error}[$i]; 
	$kind = $error->{kind}; 
	$stack = $error->{stack}; 
	$numerrors++; 
	$nondistincthashes++;    # record total number of errors

	# Extract the stack hash and fuzzy stack hash
	# code for oldstackhash and fuzzystackhash in libstackhash.pl 
	# Check for error in oldstackhash, catch it if it happens
	$stackhash =  eval{oldstackhash($error)};
	if (! defined $stackhash)
	{
	    # Create "malformedxml" directory if it does not yet exist.
	    if (! (-e "malformedxml"))
	    {
		system("mkdir malformedxml");
	    }
	    system("cp $xmlname ./malformedxml/$xmlname");
	    $stackhash = ""; 
	}

	# Check for error in fuzzyhash, catch it if it happens.
	$fuzzyhash = eval{fuzzystackhash($error)}; 
	if (! defined $fuzzyhash)
	{

	    # Create "malformedxml" directory if it does not yet exist.
	    if (! (-e "malformedxml"))
	    {
		system("mkdir malformedxml");
	    }
	    system("cp $xmlname ./malformedxml/$xmlname");
	    $fuzzyhash = ""; 
	}

	# Send bug info to database
	# Check first that we have a non-empty kind and stackhash
        if (! ($kind eq "") && ! ($stackhash eq ""))
        { 
	    record_bug(
		$uuid, 
		$seqno, 
		$filename,
		$kind, 
		$stackhash, 
		$fuzztype,
		$fuzzyhash
		); 
        }

	# Is this error an invalidread or invalidwrite?
        # Use this for reporting
        if ($kind eq 'InvalidRead' || $kind eq 'InvalidWrite')
        {
	    $foundInvalidRW = 1; 
        }
	

        # If we have not seen this stack hash, 
        # then copy the memcheck output and test case
        # to the appropriate directory. Create if needed. 
    	if (! (exists $stacks_seen{$stackhash}) )
	{
	    $stacks_seen{$stackhash} = 1; 
	    $distincthashes++; 
	    $kinds{$kind}++; 
	    
	    if (! (-e "results/errors/$kind"))
	    {
		system("mkdir results/errors/$kind/"); 
	    }

	    if (! (-e "results/errors/$kind/$stackhash"))
	    {
		system("mkdir results/errors/$kind/$stackhash");
	    }

	    if (! (-e "results/errors/$kind/$stackhash/$xmlname"))
	    {	       
              # Intended to copy file, memcheck output, and stdout/novgstdout
		system("cp $filename* results/errors/$kind/$stackhash/"); 
		
	      # Upload .tgz of file,memcheck, stdout/novgstdout to metafuzz.com
		record_file($uuid, $seqno, $seqno, $filename, $kind, $stackhash, $fuzztype, $filename); 
	    }
	}
	$i++;
    }
}




sub triage
{
    $triageinputfile = @_[0]; 
    $triagecommandline = @_[1];
    $deleteifnothing = @_[2]; 
    $seqno = @_[3]; 
    $fuzztype = @_[4];
    $uuid = @_[5]; 

    $foundVGBugs = 0; 
    $foundInvalidRW = 0; 
    $foundSegfault = 0;


    # remove any leftover core files
    if (-e "core") 
    {
	$result = system("rm core"); 
    }

    print "running memcheck: " . $triagecommandline . "\n";
    $vgcommand = "ulimit -t $timelimit_triage; $valgrind --tool=memcheck --xml=yes --log-file-exactly=$triageinputfile-memcheck $triagecommandline > $triageinputfile-stdout 2> $triageinputfile-stderr ";
    print "vgcommand: $vgcommand \n"; 
     
    $result = system($vgcommand); 

    # Check whether memcheck produced an output
    if (! (-e "$triageinputfile-memcheck"))
    {
      print "No memcheck output! \n"; 
    }

    # Process the resulting memcheck file
    process_memcheck($triageinputfile, $seqno, $fuzztype, $uuid); 

    # Check for core file or nonzero result after valgrind run 
    if ($result != 0) 
    {
	$stackhash = (($uuid<<15) | $result); 
	print("Found nonzero result test case!\n"); 
        $foundSegfault = 1; 

	$crashkind = "result$result"; 
        if (! (-e "results/errors/crashes/$crashkind"))
        {
	    system("mkdir results/errors/crashes/$crashkind"); 
        }

	record_bug($uuid, $seqno, $triageinputfile, $crashkind, $stackhash, $fuzztype); 
	record_file($uuid, $seqno, $seqno, $triageinputfile, $crashkind, $stackhash, $fuzztype, $triageinputfile); 

	# If we have a core file, include it in a .tgz for storing
	# otherwise just create a .tgz with test case and output
	if (-e "*core*")   
        {
	    $result = system("tar czf $uuid-$seqno-$crashkind.tgz --exclude=libscore.pl *core* $triageinputfile $triageinputfile-stdout $triageinputfile-stderr $triageinputfile-memcheck"); 
	    $result = system("rm $triageinputfile-stdout $triageinputfile-novg-stderr $triageinputfile-memcheck"); 
	}
	else
	{
	    $result = system("tar czf $uuid-$seqno-$crashkind.tgz --exclude=libscore.pl $triageinputfile $triageinputfile-stdout $triageinputfile-stderr $triageinputfile-memcheck"); 
	    $result = system("rm $triageinputfile-stdout $triageinputfile-stderr $triageinputfile-memcheck"); 
	}
	$result = system("mv $uuid-$seqno-$crashkind.tgz results/errors/crashes/$crashkind"); 
    	$total_crashes++; 
    }


    # Now run without valgrind - in case of bugs which 
    # express only when valgrind is running (e.g. flashplayer!)
    print "running without vg: " . $triagecommandline . "\n"; 
    $result = system("ulimit -t $timelimit_triage; $triagecommandline > $triageinputfile-novg-stdout 2> $triageinputfile-novg-stderr"); 
  
    # Check for core file or nonzero result after no-valgrind run 
    if ($result != 0) 
    {
	$stackhash = (($uuid<<15) | $result); 
	print("Found nonzero result test case!\n"); 
        $foundSegfault = 1; 
	
	$crashkind = "result$result"; 

	record_bug($uuid, $seqno, $triageinputfile, $crashkind, $stackhash, $fuzztype); 
	record_file($uuid, $seqno, $seqno, $triageinputfile, $crashkind, $stackhash, $fuzztype, $triageinputfile); 

        if (! (-e "results/errors/crashes/$crashkind"))
        {
	    system("mkdir results/errors/crashes/$crashkind"); 
        }

	if (-e "*core*")   
        {
	    $result = system("tar czf $uuid-$seqno-$crashkind.tgz --exclude=libscore.pl *core* $triageinputfile $triageinputfile-novg-stdout $triageinputfile-novg-stderr"); 
	    $result = system("rm *core* $triageinputfile-novg-stdout $triageinputfile-novg-stderr"); 
	}
	else
	{
	    $result = system("tar czf $uuid-$seqno-$crashkind.tgz --exclude=libscore.pl *core* $triageinputfile $triageinputfile-novg-stdout $triageinputfile-novg-stderr"); 
	    $result = system("rm $triageinputfile-novg-stdout $triageinputfile-novg-stderr"); 
	}
	$result = system("mv $uuid-$seqno-$crashkind.tgz results/errors/crashes/$crashkind"); 
    	$total_crashes++; 
    }

    # Previously deleted the $triageinputfile here. 
    # Now shifting to have the caller delete / move file when done 
    # Will eventually change the subroutine call signature 

    $total_triaged++;
}



1; 

