# args:  jobname inputname {zzuf} ...commandline...

$jobname = $ARGV[0]; 
$inputname = $ARGV[1]; 
$zzuf = $ARGV[2]; 
$argnum = $#ARGV; 

if ($zzuf eq "zzuf")
{
   $argcount = 3; 
}
else
{
   $argcount = 2;
}

while ($argcount <= $argnum)
{
    $commandline = $commandline . " " . $ARGV[$argcount];
    $argcount++;
}


$prefix = $ENV{CC_TEST_PREFIX}; 
$valgrind = $ENV{VG_CC_PATH}; 
$stp = $ENV{STP_PATH}; 
$mplayerpath = $ENV{MPLAYERPATH}; 
$zzuf_path = $ENV{ZZUF_PATH}; 
$mf_email = $ENV{MF_EMAIL}; 
$loop_path = $ENV{LOOP_PATH};
$loop_threshold = $ENV{LOOP_THRESHOLD};
$loop_keep = $ENV{LOOP_KEEP};

# sanity checking

# check mplayer path
if ($mplayerpath eq "")
{
   die "You need to set the environment variable MPLAYERPATH! \n"; 
}

# check presence of VG-CC 
if (! (-e $valgrind))
{
   die "Could not find Valgrind at path '$valgrind '. Please fix the VC_CC_PATH environment variable!\n"; 
}

# check presence of STP 

if (! (-e $stp))
{
   die "Could not find STP at path '$stp '. Please fix the STP_PATH environment variable!\n"; 
}

# check for non-empty prefix
if ($prefix eq "")
{
   die "Empty test directory prefix! Please set the CC_TEST_PREFIX environment variable!\n";
}

# check for existence of runtemplate directory
if (! (-e "$prefix/runtemplate"))
{
   die "Could not find the runtemplate directory at '$prefix/runtemplate'. Please check the CC_TEST_PREFIX environment variable!\n";
}

# check inputname has no /, or remove if it does 
@splitinputname = split(/\\/,$inputname); 
$inputname = $splitinputname[-1];  

# check non-empty jobname 
if ($jobname eq "")
{
   die "Empty job name! Please specify a job name as the first argument to this script.";
}


#set up directory
system("mkdir $prefix/$jobname"); 
system("cp -r $prefix/runtemplate/* $prefix/$jobname"); 

if (-e "$inputname")
{
   system("cp $inputname $prefix/$jobname"); 
}
else
{
   die "Cannot find $inputname to copy to $prefix/$jobname !";
}

#output batch script
#
print "#!/bin/sh \n"; 
print "### Set the job name\n";  
print "#PBS -N $jobname \n"; 

print "### Declare myprogram non-rerunable\n";
print "#PBS -r n\n"; 

print "#PBS -m abe\n";
print "#PBS -M dmolnar@cs.berkeley.edu\n";

print "### Optionally specifiy destinations for your myprogram's output\n"; 
print "### Specify localhost and an NFS filesystem to prevent file copy errors.\n"; 
print "#PBS -e localhost:$prefix/$jobname/$jobname.err\n"; 
print "#PBS -o localhost:$prefix/$jobname/$jobname.log\n"; 

print "### Set the queue to \"batch\", the only available queue.\n"; 
print "#PBS -q batch\n"; 

print "#PBS -l nodes=1:cpu3000,walltime=24:20:00\n"; 

print "cd $prefix/$jobname \n"; 

print "### Run some informational commands.\n"; 
print "echo Running on host `hostname` \n"; 
print "echo Time is `date` \n"; 
print "echo Directory is `pwd` \n";
print "echo This jobs runs on the following processors:\n";
print "echo `cat $PBS_NODEFILE`\n"; 
print "### Define number of processors\n";
print "NPROCS=\`wc -l < \$PBS_NODEFILE\`\n"; 
print "echo This job has allocated \$NPROCS cpus\n"; 

print "export CC_TEST_PREFIX=$prefix\n"; 
print "export VG_CC_PATH=$valgrind\n"; 
print "export ZZUF_PATH=$zzuf_path\n"; 
print "export STP_PATH=$stp\n"; 
print "export MF_EMAIL=$mf_email\n"; 
print "export LD_LIBRARY_PATH=/work/dmolnar/tmplib32/lib:\$LD_LIBRARY_PATH\n";
print "export LOOP_PATH=$loop_path\n";
print "export LOOP_THRESHOLD=$loop_threshold\n";
print "export LOOP_KEEP=$loop_keep\n";

### Do NOT enable core dumps for now due to space crunch on PSI cluster!
# print "# enable core dumps\n"; 
# print "ulimit -c unlimited\n";

if ($zzuf eq "zzuf")
{
   $scriptname = "zzuf.pl"; 
}
else
{
   $scriptname = "gensearch.pl"; 
}

print "/usr/X11R6/bin/perl $prefix/$jobname/$scriptname $inputname $commandline < /dev/null\n"; 
