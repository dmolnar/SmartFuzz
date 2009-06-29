
while (<>)
{
	chop; 
	$num = hex($_);
	printf "%d\n", $num;
}

