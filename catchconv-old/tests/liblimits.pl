
# Time limits for different tasks spawned by main test generation process.
# Times are in seconds. 

$timelimit_triage = 300;
$timelimit_score = 300;
$timelimit_symexec = 300*60;
$timelimit_solver = 300*60; 

# Time limit for the entire process.
# Default is 24 hours
$timelimit_total = 24*60*60; 

# Check for environment variable overriding default
if (defined $ENV{SF_TIMELIMIT_TOTAL})
{
    $timelimit_total = $ENV{SF_TIMELIMIT_TOTAL}; 
}

# Need this or require will fail! 
1; 
