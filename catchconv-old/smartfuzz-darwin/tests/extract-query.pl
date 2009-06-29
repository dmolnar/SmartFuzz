
$constraintfile = $ARGV[0];
$target_query = $ARGV[1];

open (RESULT, "$constraintfile") or die "can't open constraints!"; 

$cur_query = 0; 

while (<RESULT>)
{

  if ( /QUERY/)
  {
      $cur_query++; 

      if ($cur_query == $target_query)
      {

	    @xxxsplit = split(/XXX/);
	    
	    if (/JUMPCOND/)
	    {
		$headnum = $querylinenum - 2; 
		$jumpcondp = 1;
		if ($skipjumpconds == 1)
		{
		    next; 
		} 
	    }
	    else
	    {
		$headnum = $querylinenum; 
		$jumpcondp = 0; 
	    }
	
	$query = $xxxsplit[1]; 
	
	print "QUERY: $query \n"; 
	chop $query; 
	
	    $querynum = $target_query; 
	$result = system("head -n$headnum driverbase > query-$querynum-tmp");
        $result = system("echo \"ASSERT(TRUE);\n$query\" >> query-$querynum-tmp");  
        $result = system("grep -v DWARF query-$querynum-tmp > query-$querynum-tmp2");  
	$result = system("./rco < query-$querynum-tmp2 > query-$querynum-tmp3"); 
        $result = system("grep -v ASSERT\\(TRUE\\) query-$querynum-tmp3 > query-$querynum"); 	    

	# Delete the tmp query files. 
        $result = system("rm query-$querynum-tmp"); 
	$result = system("rm query-$querynum-tmp2"); 
	$result = system("rm query-$querynum-tmp3"); 
      }
  }
}
