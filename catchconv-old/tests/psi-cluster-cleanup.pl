$prefix = $ENV{CC_PREFIX};

if ($prefix eq "")
{
   die "Please set up your metafuzz environment!\n"; 
}

$prefix = "$prefix/tests"; 

# Grab the current Torque queue
$cur_queue = `showq`; 

# Archive all results directories
$archivename = "results_archive.tar.bz2";  
system("find $prefix/* | grep \"results\" | xargs -I{} tar cjf $archivename --exclude=runtemplate {}"); 

# Delete all non-runtemplate directories
# NEXTVERSION: check for and avoid directories which host running jobs! 
# No easy way to do so in this version because no easy way to determine
# the job number for a given directory
system("find $prefix/* | grep -v \"runtemplate\" - | xargs -I{} rm -rf {}"); 

