
## BB scoring components for gensearch and zzuf 
## requires $valgrind to be defined 

require 'liblimits.pl'; 

sub new_bbs 
{

    %count = (); 
    %new = (); 
    @union = @int = @diff = ();
    $numnew = 0; 

    # read in current list of bbs
    open (CURBBS, "curbbs"); 
    @current = <CURBBS>; 
   
    # read in the test case list of bbs
    open (FILEBBS, "@_[0]-bbs"); 
    @file = <FILEBBS>;

    # compute union, intersection, return cardinality of intersection 
    foreach $element (@file) { $new{$element}++ }; 
    foreach $element (@current, @file) { $count{$element}++}; 
    foreach $element ( keys %count) 
    {
	push @union, $element; 

	if ($count{$element} == 1 && $new{$element} == 1)
	{
	    push @int, $element; 
	    $numnew++; 
	}
    }

   # write union to "curbbs"
   # first close old current BB list
    close CURBBS;

   # open new current BB list
    open (NEWBBS, ">newbbs");
    foreach $element (@union)
    {
	print NEWBBS "$element"; 
    }
   # move new to current, overwrite old 
    system("mv newbbs curbbs"); 
    close NEWBBS;
    close FILEBBS; 

    return $numnew; 
}

sub score
{	
    $scorecommandline = @_[0]; 
    $sc_inputfile = @_[1]; 
    print "computing BBs: " . $scorecommandline . "\n"; 

    $result = system("ulimit -t $timelimit_score; $valgrind --tool=bbcoverage --quiet --log-file-exactly=$sc_inputfile-bbs --input-file=$sc_inputfile $scorecommandline > /dev/null 2> /dev/null"); 

    $inputfilescore = new_bbs($sc_inputfile); 

    # Sometimes BB tool core dumps; until we fix it, make sure
    # to clean up the mess afterwards. Otherwise triage sees it
    # and mistakes the core for a core dump due to the input file alone.
    if (-e "*core*")
    {
	system("rm *core*"); 
    }
    print "new BBs: $inputfilescore \n"; 

    # Delete no longer needed bbs file from input 

    if (-e "$sc_inputfile-bbs")
    {
	system("rm $sc_inputfile-bbs");
    }
    return $inputfilescore;
}

1; 
