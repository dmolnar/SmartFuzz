
use XML::Simple;
use Data::Dumper; 
use Digest::SHA qw(sha256 sha256_hex sha256_base64);

sub oldstackhash
{
    my ($error) = @_;
    $stack = $error->{stack};
    if (ref($stack) eq 'ARRAY')
    {
	$stackhash = $error->{'stack'}[0]->{'stackhash'}; 
    }
    else
    {
	$stackhash = $stack->{stackhash}; 
    }
    return $stackhash; 
}

sub fuzzystackhash
{
    my ($error) = @_;
    my $stack = $error->{stack}; 
    my $frame; 
    
    if (ref($stack) eq 'ARRAY')
    {
	$frame = $error->{'stack'}[0]->{frame};
    }
    else
    {
	$frame = $stack->{frame}; 
    }
    $curframe = 0; 
    $fuzzystring = "";

    $numframes = eval{@$frame}; 
    if (! defined $numframes)
    {
       $numframes = 0; 
    }
   
    #Depends on perl returning empty string when referencing $curframe
    #that does not exist. 
    while ($curframe < 3 && $numframes) 
    {
	$frameobj = $frame->[$curframe]; 	
	$fuzzystring = $fuzzystring . $frameobj->{'fn'};
	$line = $frameobj->{'line'};
	chop $line; 
	$fuzzystring = $fuzzystring . $line; 
	$curframe++;   
    }
    $hash = sha256_hex($fuzzystring); 
    return $hash;  
}

# require fails without this
1;
