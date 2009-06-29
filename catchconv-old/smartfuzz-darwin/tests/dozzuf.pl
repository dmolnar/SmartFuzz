$prefix = $ENV{CC_PREFIX}; 
$inputfile = $ARGV[0];
$argnum = $#ARGV;
$argcount = 1;
$commandline = "";

while ($argcount <= $argnum)
{
    $commandline = $commandline . " " . $ARGV[$argcount];
    $argcount++;
}

# check for non-empty prefix
if ($prefix eq "")
{
   die "Empty test directory prefix! Please set the CC_TEST_PREFIX environment variable!\n";
}

# check for existence of runtemplate directory
if (! (-e "$prefix/tests/runtemplate"))
{
   die "Could not find the runtemplate directory at '$prefix/tests/runtemplate'. Please check the CC_PREFIX environment variable!\n";
}

$curtime = time();
$newtestdir = "$prefix/tests/zzuf-$curtime-$inputfile"; 

if (! (-e "$newtestdir"))
{
   system("mkdir $newtestdir"); 
}

print "Copying $inputfile to $newtestdir \n"; 
system("cp $inputfile $newtestdir"); 
system("cp -r $prefix/tests/runtemplate/* $newtestdir"); 
chdir "$newtestdir"; 
print "Starting zzuf on $inputfile in $newtestdir \n"; 
exec("perl $prefix/bin/zzuf.pl $inputfile $commandline"); 
