
$file = $ARGV[0]; 

print $file . "\n"; 

open(NEWTEST, "+<$file"); 

while (<STDIN>)
{
    if ($_ =~ m/INPUT/)
    {
	print $_; 
	@spacesplit = split(/ /);
	@offsetsplit = split(/OFFSET/, $spacesplit[1]); 
	$offset = $offsetsplit[1]; 
	print "offset: " . $offset . "\n"; 
       
	@hexsplit = split(/0hex/, $spacesplit[4]); 
	$value = $hexsplit[1]; 
	print "value: " . $value . "\n"; 
	
	@chars = split(//, $value); 

	$bytevalue0 = chr( hex($chars[0] . $chars[1])); 
	$bytevalue1 = chr( hex($chars[2] . $chars[3])); 
	$bytevalue2 = chr( hex($chars[4] . $chars[5])); 
	$bytevalue3 = chr( hex($chars[6] . $chars[7])); 
	

	use Fcntl 'SEEK_SET'; 

	print "byte3: $chars[6]$chars[7] byte2: $chars[4]$chars[5] byte1: $chars[2]$chars[3] byte0: $chars[0]$chars[1] \n";
	$numoffset = hex($offset);
	sysseek(NEWTEST, $numoffset, SEEK_SET);
	syswrite(NEWTEST, $bytevalue3); 
	syswrite(NEWTEST, $bytevalue2); 
	syswrite(NEWTEST, $bytevalue1); 
	syswrite(NEWTEST, $bytevalue0); 
	
    }

}

close(NEWTEST); 
