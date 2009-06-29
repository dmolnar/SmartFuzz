## metafuzz recording functions for gensearch and zzuf
$METAFUZZ_URL = "http://www.metafuzz.com/dev/dmolnar/metafuzz.com";

use XML::Simple;
use Data::Dumper;  


# For bugs aggregation
@bugs = (); 
$batch_bugs_threshold = 1; 
$num_bugs = 0; 

# For testcase aggregation
@testcases = (); 
$batch_testcases_threshold = 1; 
$num_testcases = 0; 

# For queries aggregation 
@queries = (); 
$batch_queries_threshold = 1; 
$num_queries = 0; 



# via koders.com
sub UrlEncode { 
    my @letters = split(//, shift); 
    my @save = ('a'.. 'z', 'A' .. 'Z', '0'.. '9', '-', '_', '.', '!', '~', '*', "'", '(', ')');  

    foreach my $letter (@letters) {
	my $pattern = quotemeta($letter); 
	if (not grep(/$pattern/, @safe)) {
	    $letter = sprintf("%%%02x", ord($letter)); 
	}
    }
    return join('', @letters); 
}

sub SpacesToUnderscores
{
	my @letters = split(//, shift); 
	foreach my $letter (@letters) {
	if ($letter eq " ")
        {
	    $letter = "_"; 
        }
     }
     return join('', @letters); 
}

# Upload file to metafuzz.com
sub record_file
{

   my($tc_uuid, 
      $tc_seqno,
      $tc_answernum, 
      $tc_filename,
      $tc_bugkind, 
      $tc_stackhash, 
      $tc_fuzztype,
      $tc_testfilename,
      ) = @_; 

   print "Record file stackhash: $tc_stackhash \n"; 
    if ($tc_stackhash eq "")
    {
	return; 
    } 



   $tc_bugkind = SpacesToUnderscores($tc_bugkind); 
   $archive = "${tc_uuid}-${tc_seqno}-${tc_stackhash}-${tc_bugkind}.tgz"; 
   print "Record file: $archive  with filename $tc_testfilename \n"; 
   system("tar czf $archive $tc_testfilename*"); 
   $uploadname = "@" . $archive; 
   $uploadurl = "$METAFUZZ_URL/uploadtc.php";

   system("curl -F \"uploadedtc=$uploadname\" $uploadurl"); 
   system("rm $archive"); 	
}

# Send information about individual query to database
sub record_query
{
    my($tc_uuid, 
       $tc_seqno,
       $tc_invalidp,
       $tc_querystring,
       $tc_querynum,
       $tc_solvertype,
       $tc_querysize,
       $tc_prefiltersize,
       $tc_solvertime,
       $tc_seedfile,
       $tc_querytype
       ) = @_; 


    $tc_querystring = UrlEncode($tc_querystring); 
    $tc_seedfile = UrlEncode($tc_seedfile); 
    $tc_querysize = UrlEncode($tc_querysize); 
    $tc_querytype = UrlEncode($tc_querytype); 

    # XMLencode the new queryinfo
    # NOTE: we need to use my() here, otherwise subsequent 
    # invocations of this function will overwrite previously
    # declared values of %newquery: perl scope
    # defaults to global! 
    my %newquery = (); 
    $newquery{'uuid'} = $tc_uuid;
    $newquery{'seqno'} = $tc_seqno; 
    $newquery{'invalidp'} = $tc_invalidp; 
    $newquery{'querystring'} = $tc_querystring; 
    $newquery{'querynum'} = $tc_querynum; 
    $newquery{'solvertype'} = $tc_solvertype;
    $newquery{'querysize'} = $tc_querysize;
    $newquery{'prefiltersize'} = $tc_prefiltersize;
    $newquery{'solvertime'} = $tc_solvertime;
    $newquery{'seedfile'} = $tc_seedfile;
    $newquery{'querytype'} = $tc_querytype; 
    $queries[$num_queries] = \%newquery; 
    
   
    print "Added to query aggregate: " . XMLout(\%newquery) . "\n"; 
    $num_queries++; 
    print "Currently at $num_queries out of $batch_queries_threshold query info reports\n"; 
    
    if ($num_queries >= $batch_queries_threshold)
    {
	$queriesxml = XMLout(\@queries); 
	my $curl = WWW::Curl::Easy->new(); 

	my $url= "$METAFUZZ_URL/doqueriesaggregate.php";
	print "Aggregate queries URL : $url \n"; 
	print "XML : $queriesxml \n"; 
	$curl->setopt(CURLOPT_URL, $url); 
	$curl->setopt(CURLOPT_POST, 1); 
	$curl->setopt(CURLOPT_POSTFIELDS,"xmlqueries=".$queriesxml); 
	$curl->setopt(CURLOPT_FOLLOWLOCATION, 1);    
	$curl->setopt(CURLOPT_URL, $url); 

	print "URL: $url \n"; 
	if ($curl->perform() != 0)
	{
	    print "Curl failed :: " . $curl->errbuf . "  URL:" . $url . "\n"; 
	}
	else
	{
	    $num_queries = 0; 
	    @queries = (); 
	}
    }
}


# Send information about the test run to database
# Plus update file in local directory with test run info 
sub record_run
{
    my($tc_uuid, 
       $tc_email, 
       $tc_commandline, 
       $tc_timespent, 
       $tc_numtests,
       $tc_totalbuckets,
       $tc_uniquebuckets,
       $tc_blocksadded,
       $tc_inputfile,
       $tc_resultslink,
       $tc_fuzztype
       ) = @_; 


    $tc_email_enc = UrlEncode($tc_email); 
    $tc_commandline_enc = UrlEncode($tc_commandline); 
    $tc_inputfile_enc = UrlEncode($tc_inputfile); 
    $tc_resultslink_enc = UrlEncode($tc_resultslink);
    chomp $tc_resultslink; 

    print "Blocks added: $tc_blocksadded \n"; 

    my $curl = WWW::Curl::Easy->new(); 
   
    my $url= "$METAFUZZ_URL/dorunresults.php?uuid=$tc_uuid";
    $url = $url . "&email=$tc_email_enc";
    $url = $url . "&commandline=$tc_commandline_enc";
    $url = $url . "&fuzztype=$tc_fuzztype";
    $url = $url . "&timespent=$tc_timespent"; 
    $url = $url . "&numtests=$tc_numtests"; 
    $url = $url . "&totalbuckets=$tc_totalbuckets"; 
    $url = $url . "&uniquebuckets=$tc_uniquebuckets"; 
    $url = $url . "&blocksadded=$tc_blocksadded"; 
    $url = $url . "&inputfile=$tc_inputfile_enc";
    $url = $url . "&resultslink=$tc_resultslink_enc";
    

   $curl->setopt(CURLOPT_URL, $url); 

    print "URL: $url \n"; 
    if ($curl->perform() != 0)
    {
	print "Curl failed :: " . $curl->errbuf . "  URL:" . $url . "\n"; 
    }

    # Open file in run directory, output this data 
    open (RUNDATA, "+>runinfo"); 
    print RUNDATA "UUID: $tc_uuid \n"; 
    print RUNDATA "Email: $tc_email \n"; 
    print RUNDATA "Commandline: $tc_commandline \n"; 
    print RUNDATA "FuzzerType: $tc_fuzztype \n"; 
    print RUNDATA "TimeSpent: $tc_timespent \n"; 
    print RUNDATA "NumTests: $tc_numtests \n"; 
    print RUNDATA "TotalBuckets: $tc_totalbuckets \n";
    print RUNDATA "UniqueBuckets: $tc_uniquebuckets \n"; 
    print RUNDATA "BlocksAdded: $tc_blocksadded \n";
    print RUNDATA "InputFile: $tc_inputfile \n"; 
    print RUNDATA "ResultsLink: $tc_resultslink \n"; 

    # Check if we are on PSI cluster, if so record job # and job name
    $jobid = $ENV{PBS_O_JOBID};
    $jobname = $ENV{PBS_JOBNAME};
    
    print "JobID: $jobid \n";

    if ( !($jobid eq "") && !($jobname eq ""))
    {
	print RUNDATA "PBSJobID: $jobid \n";
	print RUNDATA "PBSJobName: $jobname \n";
    }

    close RUNDATA; 
}

# Send information about a test case to database 
sub record_bug
{
   my($tcuuid, 
      $tcanswernum, 
      $tcfilename,
      $tc_kind, 
      $tc_stackhash,
      $tc_fuzztype,
      $tc_fuzzystackhash
       ) = @_; 

   # XMLencode the new bug
   # NOTE: we need to use my() here, otherwise subsequent 
   # invocations of this function will overwrite previously
   # declared values of %newbug by default: perl scope
   # defaults to global! 
   my %newbug = (); 
   $newbug{'uuid'} = $tcuuid;
   $newbug{'seqno'} = $tcanswernum; 
   $newbug{'filename'} = $tcfilename; 
   $newbug{'type'} = SpacesToUnderscores($tc_kind); 
   $newbug{'stackhash'} = $tc_stackhash; 
   $newbug{'fuzzystackhash'} = $tc_fuzzystackhash; 
   $newbug{'fuzztype'} = $tc_fuzztype; 
   $bugs[$num_bugs] = \%newbug; 
   
   print "Added to bug aggregate: " . XMLout(\%newbug) . "\n"; 
   $num_bugs++; 
   print "Currently at $num_bugs out of $batch_bugs_threshold bug info reports\n"; 
   

   # If we have enough bugs, upload them
   if ($num_bugs >= $batch_bugs_threshold)
   {
       my $curl = WWW::Curl::Easy->new(); 
       $bugsxml = XMLout(\@bugs); 

       my $url= "$METAFUZZ_URL/dobugsaggregate.php";

       print "Aggregate bugs URL : $url \n"; 

       $curl->setopt(CURLOPT_URL, $url); 
       $curl->setopt(CURLOPT_POST, 1); 
       $curl->setopt(CURLOPT_POSTFIELDS,"xmlbugs=".$bugsxml); 
       $curl->setopt(CURLOPT_FOLLOWLOCATION, 1); 
       
       if ($curl->perform() != 0)
       {
	   print "Curl failed :: " . $curl->errbuf . "  URL:" . $url . "\n"; 
       }
       else
       {
	   $num_bugs = 0;
	   @bugs = (); 
       }
   }
}

sub record_testcase 
{
   my($tcuuid, 
      $tcanswernum, 
      $tcfilename, 
      $tc_old_blocks_added,
      $tc_score, 
      $tc_gen, 
      $tcparent, 
      $tc_vgbugs, 
      $tc_invalidRW,
      $tc_segfault) = @_; 


   # XMLencode the new test case
   # NOTE: we need to use my() here, otherwise subsequent 
   # invocations of this function will overwrite previously
   # declared values of %newtestcase by default: perl scope
   # defaults to global! 
   my %newtestcase = (); 
   $newtestcase{'uuid'} = $tcuuid;
   $newtestcase{'seqno'} = $tcanswernum; 
   $newtestcase{'basic_blocks'} = $tc_old_blocks_added; 
   $newtestcase{'new_basic_blocks'} = $tc_score; 
   $newtestcase{'parent'} = $tcparent; 
   $newtestcase{'generation'} = $tc_gen; 
   $newtestcase{'filename'} = $tcfilename; 
   $newtestcase{'foundVGBugs'} = $tc_vgbugs; 
   $newtestcase{'foundVGInvalidRW'} = $tc_invalidRW; 
   $newtestcase{'foundSegfault'} = $tc_segfault; 
   $testcases[$num_testcases] = \%newtestcase; 
   
   print "Added to test cases aggregate: " . XMLout(\%newtestcase) . "\n"; 
   $num_testcases++; 
   print "Currently at $num_testcases out of $batch_testcases_threshold test case reports\n"; 
   
   # If we have enough test cases, XMLencode the lot and upload them 
   # otherwise add a test case entry to the batch 
   if ($num_testcases >= $batch_testcases_threshold)
   {
       my $curl = WWW::Curl::Easy->new(); 
   
       $testcasesxml = XMLout(\@testcases); 

       my $url= "$METAFUZZ_URL/dotestcasesaggregate.php";
       
       
       $curl->setopt(CURLOPT_URL, $url); 
       $curl->setopt(CURLOPT_POST, 1); 
       $curl->setopt(CURLOPT_POSTFIELDS,"xmltestcases=".$testcasesxml); 
       $curl->setopt(CURLOPT_FOLLOWLOCATION, 1); 
       
       $curl->setopt(CURLOPT_URL, $url); 
   
       print "URL : $url \n";

       if ($curl->perform() != 0)
       {
	   print "Curl failed :: " . $curl->errbuf . "  URL:" . $url . "\n"; 
       }
       else 
      {
	  $num_testcases = 0; 
	  @testcases = (); 
      }   
   }
}

# Include will fail without this! 
1; 
