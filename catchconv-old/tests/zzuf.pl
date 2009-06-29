use lib './WWW-Curl-4.00/lib';
use lib './WWW-Curl-4.00/blib/lib';
use lib './WWW-Curl-4.00/blib/arch/auto/WWW/Curl';
use lib './XML-Parser-2.36/blib/lib/';
use lib './XML-Parser-2.36/blib/arch/auto/XML/Parser/Expat';
use lib './XML-Simple-2.18/lib';
use lib './Digest-SHA-5.47/lib'; 
use lib './Digest-SHA-5.47/blib/lib'; 
use lib './Digest-SHA-5.47/blib/arch/auto/Digest/SHA'; 

require 'libstats.pl'; 
require 'libtriage.pl';
require 'librecord.pl'; 
require 'libscore.pl'; 
require 'libfiledup.pl';
require 'liblimits.pl'; 

use XML::Simple;
use WWW::Curl::Easy; 

$result = system("ulimit -c unlimited"); 
$result = system("ulimit -s unlimited"); 

$zzuf = $ENV{ZZUF_PATH}; 
$valgrind =  $ENV{VG_CC_PATH};
$mf_email = $ENV{MF_EMAIL}; 
$pwd = qx("pwd"); 

# stats
$init_blocks = 0; 
$blocks_added = 0; 
$total_created = 0; 
$total_triaged = 0;
$jumpcond_created = 0; 
$init_time = 0;
$total_time = 0; 
$time_start = time; 
$distincthashes = 0; 

%stacks_seen = (); 
%kinds = (); 

$num_crashes = 0; 
$num_invalidWrite = 0; 
$num_invalidRead = 0; 

$uuid = int(rand(1000000));

$foundVGBugs = 0;
$foundInvalidRW = 0;


$inputfile = $ARGV[0]; 
$argnum = $#ARGV; 
$argcount = 1;
$commandline = "";

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
system("mkdir alltestcases"); 


# Triage and score initial test case
triage($inputfile, $commandline, 0,0, "zzuf", $uuid); 

# Delete leftover stdout/stderr/memcheck file
system("rm $inputfile-novg-stderr $inputfile-novg-stdout $inputfile-stderr $inputfile-stdout $inputfile-memcheck"); 

$init_blocks = score($commandline, $inputfile); 
print "Initial # BBs: $init_blocks \n"; 

$tcnum = 0; 

# record initial test run stats 
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
	   "zzuf"
	   );



while (1)
{ 

    # check if we are over time
    $total_time = time - $time_start; 
    if ($total_time > $timelimit_total)
    {
	die("Run exceeded total time limit $timelimit_total"); 
    }

    print "\n"; 
    $tcnum++; 

    $testfile = "$tcnum-$inputfile"; 

    # Create new file with zzuf
    # To add: vary fuzzing ratio -r as well as seed -s
    # To add: pick -s from /dev/urandom !
    $result = system("$zzuf -s $tcnum < $inputfile > $testfile"); 
    $total_created++; 
    $newcommandline = $commandline;
    $newcommandline =~ s/$inputfile/$testfile/;

    # check to see if this is a duplicate file
    # if it is, delete it and continue to next
    if ( isFileDup($testfile) == 1 )
    {
	print ("Skipping duplicate file: $testfile \n"); 
	system("rm $testfile"); 
	next;  # skips rest of this iteration of loop
    }


    # Score new test case with bbcoverage 
    $score = score($newcommandline, $testfile); 
    $old_blocks_added = $blocks_added; 
    $blocks_added += $score;

    if ($score > 0)
    {
	$result = system("cp $testfile ./results/coverage"); 
    }

    # Triage new test case
    triage($testfile, $newcommandline, 1, $tcnum, "zzuf", $uuid); 

    # Move test case to alltestcases directory if
    # environment variable MF_KEEPTESTCASES is set
    # May want to add an option to delete this entirely, as 
    # zzuf never needs to revisit old test cases (unlike catchconv) 

    if (!($ENV{MF_KEEPTESTCASES} eq ""))
    {
	system("mv $testfile alltestcases/");
    }

    # Delete leftover stderr/stdout/memcheck files
    system("rm $testfile*"); 

    # Record test case stats
    record_testcase($uuid,
		    $tcnum,
		    $testfile,
		    $old_blocks_added,
		    $score,
		    0,
		    $inputfile,
		    $foundVGBugs,
		    $foundInvalidRW,
		    $foundSegfault
		    );


    # Print stats and record run_results (every 100 test cases)
    # Somewhat superfluous with metafuzz.com, but still useful 
    # to have, esp. if net is down.
    if ($tcnum % 100 == 0)
    {
       print_stats(); 
    }
    # Attempts to upload to metafuzz, also saves to disk file. 
    record_stats(
		 $uuid, 
		 $tcnum
		 );
}
