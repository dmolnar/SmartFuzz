use lib './WWW-Curl-4.00/lib';
use lib './WWW-Curl-4.00/blib/lib';
use lib './WWW-Curl-4.00/blib/arch/auto/WWW/Curl';
use lib './XML-Parser-2.36/blib/lib/'; 
use lib './XML-Parser-2.36/blib/arch/auto/XML/Parser/Expat'; 
use lib './XML-Simple-2.18/lib'; 

use POE; 
use XML::Simple; 
use WWW::Curl::Easy; 

# import functions for recording data to metafuzz.com 
require "libstats.pl"; 
require "librecord.pl";
#require "libscore.pl";
require "libtriage.pl";  
require "libfiledup.pl";

$queue = POE::Queue::Array->new(); 

$result = system("ulimit -c unlimited"); 
$result = system("ulimit -s unlimited"); 

$uuid = int(rand(1000000)); 

$generation = 0; 
$foundVGBugs = 0; 
$foundInvalidRW = 0; 

# Setup for triage 
%stacks_seen = (); 
%kinds = (); 
$numfiles = 0; 
$numerrors = 0; 
$distincthashes = 0; 

$mf_email = $ENV{MF_EMAIL}; 
$valgrind = $ENV{VG_CC_PATH}; 
$stp = $ENV{STP_PATH};  
$loop = $ENV{LOOP_PATH};
$pwd = qx("pwd"); 
$threshold=$ENV{LOOP_THRESHOLD};
$first=($ENV{LOOP_KEEP}=~/F[0-9]+/i?substr $&,1:0);
$last=($ENV{LOOP_KEEP}=~/L[0-9]+/i?substr $&,1:0);

# sanity checking - check valgrind and stp exist
if (! (-e "$valgrind"))
{
   die "Can not find valgrind at '$valgrind'. Please set the environment variable VG_CC_PATH!\n";
}

if (! (-e "$stp"))
{
   die "Can not find STP at '$stp'. Please set the environment variable STP_PATH!\n";
}


# stats
$init_blocks = 0; 
$blocks_added = 0; 
$total_created = 0; 
$total_triaged = 0;
$total_crashes = 0; 
$jumpcond_created = 0; 
$bugseeking_created = 0; 
$init_time = 0;
$total_time = 0; 
$jump_query_skip = 0;
$loop_time = 0;
$stp_time = 0;
$bug_query_skip = 0;
$path_skip = 0;

#prefix tree
$tree=undef;

# get rid of temporary file left lying around 

if (-e "curbbs")
{
   $result = system("rm curbbs"); 
}

sub expand
{
    $generation++; 

    $expandinputfile = @_[0]; 
    $expandcommandline = @_[1]; 
    $skipjumpconds = @_[2]; 

print "catchconv expanding: " . $expandcommandline . "\n"; 
print "input file: " . $expandinputfile . "\n";
print "directory: " . `pwd` . "\n"; 

    $time_pre_expand = time; 
$result = system("ulimit -t $timelimit_symexec; $valgrind --tool=catchconv --quiet --log-file-exactly=driverbase --inline-path-queries=yes --input-file=$expandinputfile $expandcommandline > /dev/null 2> /dev/null");
    $time_post_expand = time;
    $time_taken = $time_post_expand - $time_pre_expand; 
    print "SymExec task time: $time_taken \n"; 
    $time_symexec = $time_symexec + $time_taken; 


#LOOP DETECTION PART
$loop_time_begin=time;
$result = system("grep QUERY driverbase | grep JUMPCOND > QUERY");
$result = system("$loop QUERY LOOP $threshold $first $last");
open (LOOP, "LOOP") or die "can't open LOOP!";
%hash=();

while ($line=<LOOP>)
{
      if ($line=~/^0x[0-9A-F]+ [0-9]+$/)
      {
              @spacesplit0=split(/ /,$line);
              $times=0;
              while ($times<$spacesplit0[1]&&($line=<LOOP>))
              {
                      if ($line=~/^[0-9]+ [0-9]+$/)
                      {
                              ++$times;
                              @spacesplit1=split(/ /,$line);
                              for ($index=0;$index<$spacesplit1[1];++$index)
                              {
                                      $line=<LOOP>;
                                      chomp $line;
                                      $hash{$spacesplit0[0]}{$line}=0;
                              }
                      }
              }
      }
}
close(LOOP);
$loop_time_end=time;
$loop_time+=$loop_time_end-$loop_time_begin;
#-----------------------------------------------------------------------

    $querycount = 0; 
    $querylinenum = 0; 
    $answernum = 0; 
    $jumpcondp = 0; 
    $queryinvalid = 0; 
    
    open (RESULT, "driverbase") or die "can't open constraints!"; 
    open (PATH, "loop.path") or die "can't open loop path!";
    $input=<PATH>;
    close (PATH);
    @path = split(//, $input);
    $index=-2;
    while (<RESULT>)
    {
	$querylinenum++; 
	
	if ( /QUERY/)
	{
	    $querycount++; 
	    @xxxsplit = split(/XXX/);
	    @typesplit = split(/TYPE/); 
	    $querytype = $typesplit[1]; 

	    if (/JUMPCOND/)
	    {
		$headnum = $querylinenum - 2; 
		$jumpcondp = 1;
		if ($index==-2)
		{
			$index=-1;
			if (!$tree)
			{
        			$tree = [undef,undef];
				$ptr=$tree;
    			}
			else
			{
				$ptr=$tree;
				++$path_skip;
				next;
			}
		}
    		else
		{
			++$index;
			if (!$ptr->[$path[$index]])
			{
				$ptr->[$path[$index]] = [undef,undef];
				$ptr=$ptr->[$path[$index]];
			}
        		else
        		{
				$ptr=$ptr->[$path[$index]];
				++$path_skip;
				next;
			}
		}

#skip the constraint queries of the loops according to the $ENV{LOOP_KEEP} variable!!
              /0x[0-9A-F]+/;
              if (exists $hash{$&})
              {
                      if ("J" eq substr $_,10,1)
                      {
                              /JUMPCOND[0-9]+e[0-9]+c[0-9]+/;
                              $index=$&;
                      }
                      else
                      {
                              /NOT JUMPCOND[0-9]+e[0-9]+c[0-9]+/;
                              $index=$&;
                      }
                      if (!exists $hash{$&}{$index})
                      {
                              ++$jump_query_skip;
			      if ($querycount % 100 == 0)
			      {
				    record_stats($uuid,$querycount);
                                    print_stats();
			            record_run($uuid,$mf_email,$commandline,$total_time,$total_triaged,$numerrors,$distincthashes,$blocks_added,$inputfile,$pwd,"catchconv");
			      }
                              next;
                      }
              }
#---------------------------------------------------------------------------------


		if ($skipjumpconds == 1)
		{
		    next; 
		} 
	    }
	    else
	    {
		$headnum = $querylinenum; 
		$jumpcondp = 0; 
	    }
	
	$query = $xxxsplit[1]; 
	
	print "QUERY: $query \n"; 
	chomp $query; 
	
	$stp_time_begin=time;

	$result = system("head -n$headnum driverbase > query-$querycount-tmp");
        $result = system("echo \"ASSERT(TRUE);\n$query\" >> query-$querycount-tmp");  
        $result = system("grep -v DWARF query-$querycount-tmp > query-$querycount-tmp2");  
	$result = system("./rco < query-$querycount-tmp2 > query-$querycount-tmp3"); 
        $result = system("grep -v ASSERT\\(TRUE\\) query-$querycount-tmp3 > query-$querycount"); 	    

	# Delete the tmp query files. 
        $result = system("rm query-$querycount-tmp"); 
	$result = system("rm query-$querycount-tmp2"); 
	$result = system("rm query-$querycount-tmp3"); 

	$answercount = $querycount; 
	$querysizeline = `wc -l query-$answercount`; 
	@querysizesplit = split(/ /, $querysizeline); 
	$querysize = $querysizesplit[0]; 

	print "Solving query $answercount \n"; 
	system("ulimit -t $timelimit_solver; $stp -s -c -p query-$answercount > answer-$answercount"); 
	$result = system("rm query-$answercount"); 

	$stp_time_end=time;
	$stp_time+=$stp_time_end-$stp_time_begin;


	# periodically update run information
	# note the run info keeps the seed command line / input file
        if ($answercount % 100 == 0)
        {
	    record_stats($uuid,$querycount);
	    print_stats();
	    record_run($uuid,
		       $mf_email,
		       $commandline,
		       $total_time,
		       $total_triaged,
		       $numerrors,
		       $distincthashes,
		       $blocks_added,
		       $inputfile,
		       $pwd,
		       "catchconv"
                       ); 
        }


	# Check whether result is Invalid, i.e. we have a new test case
	$result = system("grep Invalid answer-$answercount"); 
	$answerline = `grep CPU answer-$answercount`;
	@answersplit = split(/ /,$answerline); 
	$solvertime = $answersplit[-2]; 


	if ($result == 0)
	{
	    print "Creating new test case for answer $answercount \n"; 
	    system("cp $expandinputfile $answercount-$expandinputfile"); 
 
	    $queryinvalid = 1; 
	    $answernum++; 
	    $total_created++;

	    if ($jumpcondp == 1)
	    {
		$jumpcond_created++;
	    }
	    else
	    {
		$bugseeking_created++; 
	    }
 
	    $newfilename = "$answercount-$expandinputfile"; 
	    system("cat answer-$answercount | perl update-file.pl $newfilename");  
	    

	    # Now that we are done with it, move the answer to the answers/ dir
	    $result = system("mv answer-$answercount answers/answer-$answercount-$expandinputfile");


	    # check to see if this is a duplicate file
	    # if it is, delete it and continue to next
	    if ( isFileDup($newfilename) == 1 )
	    {
		print ("Skipping duplicate file: $newfilename \n"); 
		system("rm $newfilename"); 
		$file_cache_hits++; 
		next;  # skips rest of this iteration of loop
	    }


	    # Compute the basic block score for the new test case
	    $newcommandline = $expandcommandline; 
	    $newcommandline =~ s/$expandinputfile/$newfilename/;

	    # queue takes lowest first, we want largest num blocks first
#	    $time_pre_coverage = time; 
	    $score=0;
#	    $score  = score($newcommandline, $newfilename); 
#	    $time_post_coverage = time; 
#	    $time_taken = $time_post_coverage - $time_pre_coverage; 
#	    $time_coverage = $time_coverage + $time_taken; 

#	    $priority = -1 * $score;
            $priority = 0;
	    $id = $queue->enqueue($priority, $newfilename); 
#	    $old_blocks_added = $blocks_added;
#	    $blocks_added += $score;

#	    if ($score > 0)
#            {
		system("cp $newfilename results/coverage/newbbs-$score-$newfilename");
#            }

	    # triage immediately - ensures triage done only once
	    $time_pre_triage = time; 
	    triage($newfilename, $newcommandline, 0, $answernum, "catchconv", $uuid); 
	    $time_post_triage = time;
	    $time_taken = $time_post_triage - $time_pre_triage; 
	    print "Triage task time: $time_taken \n"; 
	    $time_triage = $time_triage + $time_taken;
	    $time_pre_record = time;
            record_testcase($uuid, 
                            $answernum, 
                            $newfilename,
                            $old_blocks_added,
                            $score,
                            $generation,
                            $expandinputfile,  
                            $foundVGBugs,
                            $foundInvalidRW,
                            $foundSegfault
			    );
	    $time_post_record = time; 
	    $time_record = $time_record + ($time_post_record - $time_pre_record); 


	    # Move newly generated test case to holding directory unless
	    # envirnonment var MF_DISCARDTESTCASES is set
	   if (-e "$newfilename")
  	   {
	       if (($ENV{MF_DISCARDTESTCASES} eq ""))
	       {
		   system("mv $newfilename alltestcases/"); 
	       }    
               # Delete leftover stdout, memcheck outputs
               system("rm $newfilename*");  
           }
	}
	else 
	{
	    print "Valid. \n";
	    $queryinvalid = 0; 
	}

	# Now that we are done with it, move the answer to the answers/ dir  
        # if we haven't already done so above.         
        if (-e "answer-$answercount")
        {  
	    $result = system("mv answer-$answercount answers/answer-$answercount-$expandinputfile");
        }

	    # Record stats about the query
	    record_query($uuid, 
			 $answernum, 
			 $queryinvalid,
			 $query,
			 $querycount,
			 "STP",
			 $querysize,
			 $querylinenum,
			 $solvertime,
			 $expandinputfile,
			 $querytype
			 ); 
	}
    }

    print "Found $querycount queries!\n"; 
    print "Created $answernum new test cases.\n"; 
}






# Process the test case memcheck output 

sub filterall
{
    return 1; 
}


$inputfile = $ARGV[0]; 
$argnum = $#ARGV; 
$argcount = 1;
$commandline = "";

$answercount = 1;

$init_time = time; 

while ($argcount <= $argnum)
{
    $commandline = $commandline . " " . $ARGV[$argcount];
    $argcount++;
}


system("mkdir results"); 
system("mkdir results/coverage"); 
system("mkdir results/errors");
system("mkdir results/errors/crashes");
system("mkdir answers"); 
system("mkdir alltestcases"); 


#$init_blocks = score($commandline, $inputfile); 
#print "Initial # BBs: $init_blocks \n"; 


record_run($uuid,
	   $mf_email,
	   $commandline,
	   $total_time,
	   $total_triaged,
	   $numerrors,
	   $distincthashes,
	   $blocks_added,
	   $inputfile,
	   $pwd,
	   "catchconv"
	   ); 

# Triage the initial test case, then feed it to the symbolic execution 
triage($inputfile, $commandline, 0, 0, "catchconv", $uuid); 
# Remove initial input stdout/stderr/memcheck
system("rm $inputfile-stdout $inputfile-stderr $inputfile-novg-stdout $inputfile-novg-stderr $inputfile-memcheck"); 
expand($inputfile, $commandline,0); 


# expand() has now populated the queue with new test cases + scores
while ($queue->get_item_count() != 0 )
{ 
    print "\n"; 

    # Pick next element to expand, using priority queue 
    ($priority, $id, $newfilename) = $queue->dequeue_next(); 
    $newcommandline = $commandline; 
    $newcommandline =~ s/$inputfile/$newfilename/;

    # Pull $newfilename out of test case holding pen, then expand 
    # Check that the test case file exists first! 
    if (-e "alltestcases/$newfilename")
    {
	system("cp alltestcases/$newfilename ."); 
	expand($newfilename, $newcommandline, 0);
    }
    else
    {
	# Something went wrong and the test case was lost
	# Skip it and try the next one 
	print("Warning: could not find $newfilename in alltestcases directory!\n"); 
    }

    # Printing stats is kind of superflous with metafuzz, but still 
    # useful for checking progress.
    print_stats(); 
}
