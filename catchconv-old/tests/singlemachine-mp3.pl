$prefix = $ENV{CC_TEST_PREFIX};
$mplayerpath = $ENV{MPLAYERPATH};

if ($mplayerpath eq "")
{
   $mplayerpath = qx("which mplayer"); 

   if ($mplayerpath eq "")
   {
     die "No path to MP3 player set! Please set the MPLAYERPATH environment variable!\n"; 
   }
   else 
   {
     print "Auto-set mplayer path to '$mplayerpath' with which.\n"; 
   }
}
if ($prefix eq "")
{
   die "No test prefix set! Please set the CC_TEST_PREFIX environment variable!\n";
}


$filename = $ARGV[0]; 
$runtemplatepath = "$prefix/runtemplate"; 
$curtime = time();
$rundirectory = "$prefix/$curtime-mplayer-$filename"; 

#set up run directory
system("mkdir $rundirectory"); 
print "cp $filename $rundirectory/ \n"; 
system("cp $filename $rundirectory"); 
system("cp -r $runtemplatepath/* $rundirectory/"); 
print "Starting catchconv run in $rundirectory ! \n"; 
print "File name is $filename. File type is MP3. \n"; 
print "Command line is $mplayerpath $filename < /dev/null \n"; 

#start generational search
chdir $rundirectory or die "Could not change to new test directory $rundiectory !\n";
exec("perl gensearch.pl $filename $mplayerpath $filename < /dev/null");
