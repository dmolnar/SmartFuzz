use XML::Simple; 
use Data::Dumper; 

%stacks_seen = (); 
%kinds = (); 

$numfiles = 0; 
$distincthashes = 0; 

# Loop over STDIN as a list of *-memcheck file names.
while ($xmlname = <STDIN>)
{
    chop $xmlname; 

    # -e checks that the file exists on disk 
    if (! -e $xmlname) 
    {
	# Same as "continue" in C/C++ - next loop iteration.
	next; 
    }

   
    $memcheck = XMLin($xmlname); 
    $numfiles++; 

#    print "$xmlname : \n"; 
    $i = 0; 

    if (! (ref($memcheck->{error}) eq 'ARRAY'))
    {
 	next; 
    }

    $error = $memcheck->{error}[$i]; 

    while ($error->{kind})
    {
	$error = $memcheck->{error}[$i]; 
	$kind = $error->{kind}; 
	$stack = $error->{stack}; 

        # If we have an array of stacks, want the stack hash from first.
        # Memcheck always reports the error site stack first.
	if (ref($stack) eq 'ARRAY') 
	{
	    $stackhash =  $error->{'stack'}[0]->{'stackhash'}; 
	}
	else
	{
	    $stackhash = $stack->{stackhash}; 
	}

#	print $kind . " " . $stackhash . "\n";  

	# Is this a new bug bucket? 
	if (! (exists $stacks_seen{$stackhash}) )
	{
	    $stacks_seen{$stackhash} = 1; 
	    $distincthashes++; 
	    $kinds{$kind}++; 

	    if (! (-e "results/errors/$kind"))
	    {
		system("mkdir results/errors/$kind/"); 
	    }

	    if (! (-e "results/errors/$kind/$stackhash"))
	    {
		system("mkdir results/errors/$kind/$stackhash");
	    }

	    if (! (-e "results/errors/$kind/$stackhash/$xmlname"))
	    {
		system("cp $xmlname results/errors/$kind/$stackhash/"); 
	    }
	}

	$i++;
    } 
}

print "Total distinct stack hashes: " . $distincthashes . "\n"; 
foreach $bugkind (%kinds)
{
    print "Kind $bugkind : " . $kinds{$bugkind} . "\n"; 
}
print "$numfiles files examined. \n"; 
