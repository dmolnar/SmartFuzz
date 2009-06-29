$inputname = $ARGV[0];

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
print "Starting Catchconv run in $prefix/tests/$jobnamegen . Batch number is:\n";  
system("perl $bindir/output-script-singlefile.pl $jobnamegen $inputname > $scriptdir/$jobnamegen.sh");
system("qsub $scriptdir/$jobnamegen.sh"); 

print "Starting zzuf run in $prefix/tests/$jobnamezzuf . Batch number is: \n"; 
system("perl $bindir/output-script-singlefile.pl $jobnamezzuf $inputname zzuf > $scriptdir/$jobnamezzuf.sh"); 
system("qsub $scriptdir/$jobnamezzuf.sh"); 

