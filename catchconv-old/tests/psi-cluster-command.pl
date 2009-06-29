$inputname = $ARGV[0];
$argnum = $#ARGV;

$commandline = "";
$argcount = 1; 
while ($argcount <= $argnum)
{
    $commandline = $commandline . " " . $ARGV[$argcount];
    $argcount++;
}

$prefix = "$ENV{CC_PREFIX}";
$bindir = "$ENV{CC_PREFIX}/bin";
$scriptdir = "$ENV{CC_PREFIX}/qsub-scripts";
 
$curtime = time(); 
$jobnamegen = "gensearch-$curtime-$inputname"; 
$jobnamezzuf = "zzuf-$curtime-$inputname"; 

if (! (-e "$scriptdir"))
{
   system("mkdir $scriptdir"); 
}

print "Command line is: $commandline \n";
print "Input file is: $inputname \n"; 

print "Starting Catchconv run in $prefix/tests/$jobnamegen . Batch number is:\n";  
system("perl $bindir/output-script-commandline.pl $jobnamegen $inputname $commandline  > $scriptdir/$jobnamegen.sh");
system("qsub $scriptdir/$jobnamegen.sh"); 

print "Starting zzuf run in $prefix/tests/$jobnamezzuf . Batch number is: \n"; 
system("perl $bindir/output-script-commandline.pl $jobnamezzuf $inputname zzuf $commandline > $scriptdir/$jobnamezzuf.sh"); 
system("qsub $scriptdir/$jobnamezzuf.sh"); 

