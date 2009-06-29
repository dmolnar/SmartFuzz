system("gcc rco.c -O3 -DNDEBUG=1 -o rco"); 
system("mv rco runtemplate"); 
system("cp prune.pl gensearch.pl update-file.pl zzuf.pl liblimits.pl librecord.pl libscore.pl libtriage.pl libstackhash.pl libstats.pl libfiledup.pl runtemplate");
print "pwd: " .  `pwd` . "\n"; 
chdir "./runtemplate"; 
print "pwd: " .  `pwd` . "\n"; 
system("tar xzf XML-Simple-2.18.tar.gz");
system("tar xzf WWW-Curl-4.00.tar.gz");
system("tar xzf POE-cc.tar.gz"); 
system("tar xzf XML-Parser-2.36.tar.gz"); 
system("tar xzf Digest-SHA-5.47.tar.gz"); 

chdir "WWW-Curl-4.00"; 
system("perl Makefile.PL"); 
system("make"); 
chdir ".." ;

chdir "XML-Parser-2.36";
system("perl Makefile.PL"); 
system("make"); 
chdir ".."; 

chdir "Digest-SHA-5.47"; 
system("perl Makefile.PL"); 
system("make"); 
chdir ".."; 

$prefix = $ENV{CC_TEST_PREFIX};

print "prefix $prefix \n"; 

if ($prefix eq "")
{
   die "Please set the CC_TEST_PREFIX environment variable!\n"; 
}

if (! (-e "$prefix/runtemplate" ))
{
   system("mkdir $prefix/runtemplate"); 
}

system("cp -r * $prefix/runtemplate"); 
