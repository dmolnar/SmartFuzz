
use XML::Simple;
use Data::Dumper; 
use Digest::MD5 qw(md5 md5_hex md5_base64);


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
   
   #Depends on perl returning empty string when referencing $curframe
   #that does not exist. 
    
    while ($curframe < 3 && ($curframe < @$frame)) 
    {
    $frameobj = $frame->[$curframe]; 
    
    $fuzzystring = $fuzzystring . $frameobj->{'fn'};
    $line = $frameobj->{'line'};
    chop $line; 
    $fuzzystring = $fuzzystring . $line; 
    $curframe++;   
    }
   $hash = md5_hex($fuzzystring); 
   return $hash;  
}

$foo = XMLin($ARGV[0]); 
$errors = $foo->{error};

if (ref($errors) eq 'ARRAY')
{ 
foreach $curerror (@$errors)
{
$old = oldstackhash($curerror); 
$new = fuzzystackhash($curerror);

#  if (defined $old && defined $new)
#  {
  print $old . "," . $new . "\n"; 
#  }

} 
}
