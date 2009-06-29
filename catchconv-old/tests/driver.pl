

# valgrind --tool=catchconv --quiet --log-file-exactly=exp 
# --input-file=<ARGV[1]> <$ARGV[2]>

$valgrind = "/home/notroot/vg/valgrind-catchconv/inst/bin/valgrind";
$stp = "/home/notroot/stp/stp-17-10-07";
$pwd = qx("pwd"); 

$inputfile = $ARGV[0]; 

$argnum = $#ARGV; 
$argcount = 1;
$commandline = "";

$answercount = 1;


while ($argcount <= $argnum)
{
    $commandline = $commandline . " " . $ARGV[$argcount];
    $argcount++;
}

print "input file: " . $inputfile . "\n";
print "executing: " . $commandline . "\n"; 

$result = system("perl score.pl $inputfile-$answercount $commandline");

$result = system("$valgrind --tool=catchconv --quiet --log-file-exactly=driverbase --input-file=$inputfile $commandline"); 


$querycount = 0; 
$querylinenum = 0; 

open (RESULT, "driverbase") or die "can't open constraints!"; 

while (<RESULT>)
{
    $querylinenum++; 
    
    if ( /QUERY/)
    {
	$querycount++; 
	@xxxsplit = split(/XXX/);

	if (/JUMPCOND/)
	{
	    $headnum = $querylinenum; 
	}
	else
	{
	    $headnum = $querylinenum; 
	}

	$query = $xxxsplit[1]; 
	chop $query; 

	$result = system("head -n$headnum driverbase > query-$querycount-tmp");
        $result = system("echo \"ASSERT(TRUE);\n$query\" >> query-$querycount-tmp");  
	$result = system("./rco < query-$querycount-tmp > query-$querycount"); 


#	$result = system("rm query-$querycount-tmp"); 

#	$result = system("echo \"ASSERT(TRUE);\" >> query-$querycount"); 
#	$result = system("echo \"$query\" >> query-$querycount"); 

	$answercount = $querycount; 
	print "Solving query $answercount \n"; 
   system("$stp -s -c -p query-$answercount > answer-$answercount"); 
   $result = system("rm query-$answercount"); 
   print "Creating new test case for answer $answercount \n"; 
   system("cp $inputfile $inputfile-$answercount"); 
   system("cat answer-$answercount | perl update-file.pl $inputfile-$answercount");  

	$newcommandline = $commandline;
	$newfilename = "$inputfile-$answercount"; 
	$newcommandline =~ s/$inputfile/$newfilename/;
	# triage the new file
	system("perl triage.pl $inputfile-$answercount $newcommandline"); 
	# now score the new file
	system("perl score.pl $inputfile-$answercount $newcommandline");

    }
}

print "Found $querycount queries!\n"; 
$answernum = $answercount - 1; 
print "Created $answernum new test cases.\n"; 
