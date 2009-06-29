
$jobname = $ARGV[0]; 
$inputname = $ARGV[1]; 
$zzuf = $ARGV[2]; 

$prefix = "/work/dmolnar"; 

#set up directory
system("mkdir $prefix/$jobname"); 
system("cp -r $prefix/runtemplate/* $prefix/$jobname"); 
system("cp $prefix/seedfiles/$inputname $prefix/$jobname"); 

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
print "#PBS -e localhost:$prefix/$jobname.err\n"; 
print "#PBS -o localhost:$prefix/$jobname.log\n"; 

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

print "# enable core dumps\n"; 
print "ulimit -c unlimited\n";

if ($zzuf eq "zzuf")
{
   $scriptname = "zzuf.pl"; 
}
else
{
   $scriptname = "gensearch.pl"; 
}

print "/usr/X11R6/bin/perl $prefix/$jobname/$scriptname $inputname $prefix/mplayer-svn/inst/bin/mplayer $inputname < /dev/null\n"; 
