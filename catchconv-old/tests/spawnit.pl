

$inputname = $ARGV[0];

$curtime = time(); 
$jobnamegen = "gensearch-$curtime-$inputname"; 
$jobnamezzuf = "zzuf-$curtime-$inputname"; 

system("perl output-script.pl $jobnamegen $inputname > $jobnamegen.sh");
system("qsub $jobnamegen.sh"); 
system("perl output-script.pl $jobnamezzuf $inputname zzuf > $jobnamezzuf.sh"); 
system("qsub $jobnamezzuf.sh"); 

