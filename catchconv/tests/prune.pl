
# use with tac
# tac output | perl prune.pl | tac - > newoutput 

%locs = (); 


sub my_match
{
    if ($_[0] =~ m/XXX/)  # omit comments
    {
        return 0;
    } 

#   if ($_[0] =~ m/INPUT/) 
#    {
#	return 1; 
#    }

    foreach $key (keys %locs)
    {
	if ($_[0] =~ m/$key/)
	{
	    print "\nXXX matched on $key \n";  
	    return 1;
	}
    }
    return 0; 
}

sub add_locs 
{
    $curline = $_[0];
#    $delim = "(,|\s|;|\]|\[|\)|\(|<|>|\&|\||=";


  while ($curline =~ /CV/ )
   { 
       @cvs = split(/CV/, $curline); 
       @delims = split(/(\s|\)|=|">>")/, $cvs[1]); 
       $cvname = $delims[0];

      print "XXX Extractmatch-CV: " . $cvname . "\n";
       @prunedname = split(/(\(|\[|\=|>)/, $cvname); 
     
       if ($prunedname[0] != "")
       {
	   $newkey = "CV" . $prunedname[0];
       }

       print "XXX new key $newkey\n";  
	   $locs{$newkey} = 'seen'; 
      
       @restline = split(/$cvname/,$curline);
#       print $restline[1]; 
	   $curline = $restline[1] . "\n";
       
   }

    $curline = $_[0];

  while ($curline =~ /MaSt(.*?)$delim/ )
   {
#       print "Extractmatch-MaSt: " . $1 . "\n";
       $newkey = "MaSt" . $1; 
       $locs{$newkey} = 'seen';
       @restline = split(/$newkey/,$curline);
       $curline = $restline[1];
   }

    $curline = $_[0];

  while ($curline =~ /MemState(.*?)$delim/ )
   {
#       print "Extractmatch-MemState: " . $1 . "\n";
       $newkey = "MemState" . $1;
       $locs{$newkey} = 'seen'; 
       @restline = split(/$newkey/,$curline);
       $curline = $restline[1];
   }

    $curline = $_[0];

  while ($curline =~ /ARRAYREST(.*?)$delim/ )
  {
#       print "Extractmatch-MemState: " . $1 . "\n";
       $newkey = "ARRAYREST" . $1;
       $locs{$newkey} = 'seen'; 
       @restline = split(/$newkey/,$curline);
       $curline = $restline[1];
   }

  while ($curline =~ /UNCONSTRAINED(.*?)$delim/ )
  {
#       print "Extractmatch-UNCONSTRAINED: " . $1 . "\n";
       $newkey = "UNCONSTRAINED" . $1;
       $locs{$newkey} = 'seen'; 
       @restline = split(/$newkey/,$curline);
       $curline = $restline[1];
   }

}

# seed pruning with $ARGV[1]

# print $ARGV[1] . "\n"; 
$locs{$ARGV[1]} = 'seen'; 

# open file 
$filename = $ARGV[0];
open(CONFILE,$filename); 

while ( $line = <CONFILE> )
{
    if (my_match($line,%locs))
    {
	print $line; 
	add_locs($line,%locs); 
    }
}

