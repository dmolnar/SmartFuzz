
require 'librecord.pl'; 

# Declare statistics counters and initialize to zero.
$time_total = 0; 
$time_sum = 0;
$time_symexec = 0;
$time_coverage = 0; 
$time_triage = 0; 
$time_record = 0;
$elapsed = 0;
$total_created = 0;
$total_triaged = 0; 
$file_cache_hits = 0; 
$jumpcond_created = 0; 
$bugseeking_created = 0;
$init_blocks = 0;
$blocks_added = 0;
$nondistincthashes = 0; 
$distincthashes = 0; 
$init_time = 0;
$query_skip = 0;
$loop_time = 0;

sub print_stats
{
    $cur_time = time; 
    $time_total = $cur_time - $init_time; 
    $time_sum = $time_symexec + $time_coverage + $time_triage + $time_record + $loop_time;
  
    print "Total time: $time_total \n";
    print "SymExec time: $time_symexec \n";
    print "Coverage time: $time_coverage \n";
    print "Triage time: $time_triage \n";
    print "Record time: $time_record \n"; 
    print "SymExec+Coverage+Triage+Record+Loop : $time_sum \n"; 
    print "Leftover Time: " . ($time_total - $time_sum) . "\n";
    print "Test cases created: $total_created \n"; 
    print "File cache hits: $file_cache_hits \n"; 
    print "Test cases triaged: $total_triaged \n"; 
    print "Jumpcond tests created: $jumpcond_created \n"; 
    print "Bugseeking tests created: $bugseeking_created \n"; 
    print "Blocks added so far: $blocks_added (Initial: $init_blocks) \n"; 
    print "Crashes so far: $total_crashes\n"; 
    print "Total nondistinct stack hashes: $nondistincthashes \n"; 
    print "Total distinct stack hashes: " . $distincthashes . "\n"; 
    print "Query skipped: $query_skip\n";
    print "Loop time: $loop_time\n";
    print "Bug bucket kinds: \n"; 
    foreach $bugkind (%kinds)
    {
	if (!($bugkind eq ""))
	{
	    print "$bugkind : " . $kinds{$bugkind} . "\n"; 
	}
    }

}

sub record_stats
{
    my($rs_uuid,
       $rs_seqno,
       ) = @_;

    $cur_time = time; 
    $time_total = $cur_time - $init_time; 
    $time_sum = $time_symexec + $time_coverage + $time_triage + $time_record + $loop_time;
    $leftovertime = $time_total - $time_sum; 

    my $curl = WWW::Curl::Easy->new();
    
    my $url= "$METAFUZZ_URL/dorunstats.php?uuid=$rs_uuid";
    $url = $url . "&seqno=$rs_seqno";
    $url = $url . "&totaltime=$time_total";
    $url = $url . "&symexectime=$time_symexec";
    $url = $url . "&coveragetime=$time_coverage";
    $url = $url . "&triagetime=$time_triage";
    $url = $url . "&recordtime=$time_record";
    $url = $url . "&leftovertime=$leftovertime";
    $url = $url . "&totaltests=$total_created";
    $url = $url . "&filecachehits=$file_cache_hits";
    $url = $url . "&triaged=$total_triaged";
    $url = $url . "&jumpcondtests=$jumpcond_created";
    $url = $url . "&bugseekingtests=$bugseeking_created";
    $url = $url . "&blocksadded=$blocks_added";
    $url = $url . "&initblocks=$init_blocks"; 
    $url = $url . "&distinctbuckets=$distincthashes";
    $url = $url . "&nondistinctbuckets=$nondistincthashes";
#    $url = $url . "&query_skip=$query_skip";
#    $url = $url . "&loop_time=$loop_time";

    print "Test cases created: $total_created \n"; 
    print "File cache hits: $file_cache_hits \n"; 
    print "Test cases triaged: $total_triaged \n"; 
    print "Jumpcond tests created: $jumpcond_created \n"; 
    print "Bugseeking tests created: $bugseeking_created \n"; 
    print "Blocks added so far: $blocks_added (Initial: $init_blocks) \n"; 
    print "Crashes so far: $total_crashes\n"; 
    print "Total nondistinct stack hashes: $nondistincthashes \n"; 
    print "Total distinct stack hashes: " . $distincthashes . "\n"; 
    print "Query skipped: $query_skip\n";
    print "Loop Time: $loop_time\n";

    
    $curl->setopt(CURLOPT_URL, $url);
    
    print "URL: $url \n";
    if ($curl->perform() != 0)
    {
        print "Curl failed :: " . $curl->errbuf . "  URL:" . $url . "\n";
    }

    # Open file in run directory, output this data
    open (RUNSTATS, "+>runstats");
    print RUNSTATS "-------- \n"; 
    print RUNSTATS "UUID: $rs_uuid \n";
    print RUNSTATS "Seqno: $rs_seqno \n"; 
    print RUNSTATS "Total time: $time_total \n";
    print RUNSTATS "SymExec time: $time_symexec \n";
    print RUNSTATS "Coverage time: $time_coverage \n";
    print RUNSTATS "Triage time: $time_triage \n";
    print RUNSTATS "Record time: $time_record \n"; 
    print RUNSTATS "SymExec+Coverage+Triage+Record+Loop : $time_sum \n"; 
    print RUNSTATS "Leftover Time: " . ($time_total - $time_sum) . "\n";
    print RUNSTATS "Test cases created: $total_created \n"; 
    print RUNSTATS "File cache hits: $file_cache_hits \n"; 
    print RUNSTATS "Test cases triaged: $total_triaged \n"; 
    print RUNSTATS "Jumpcond tests created: $jumpcond_created \n"; 
    print RUNSTATS "Bugseeking tests created: $bugseeking_created \n"; 
    print RUNSTATS "Blocks added so far: $blocks_added (Initial: $init_blocks) \n"; 
    print RUNSTATS "Crashes so far: $total_crashes\n"; 
    print RUNSTATS "Total nondistinct stack hashes: $nondistincthashes \n"; 
    print RUNSTATS "Total distinct stack hashes: " . $distincthashes . "\n"; 
    print RUNSTATS "Query skipped: $query_skip\n";
    print RUNSTATS "Loop time: $loop_time\n";
    print RUNSTATS "Bug bucket kinds: \n"; 
    foreach $bugkind (%kinds)
    {
	if (!($bugkind eq ""))
	{
	    print RUNSTATS "$bugkind : " . $kinds{$bugkind} . "\n"; 
	}
    }

    print RUNSTATS "-------- \n"; 
}


# Need this or else require throws an error.
1; 
