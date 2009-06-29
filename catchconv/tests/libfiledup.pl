
# Checks whether a file has been seen previously in a search
# Main function takes a filename and returns TRUE or FALSE
# Works by keeping a hash of sha1sums seen in search so far

%filedupsums = (); 

sub isFileDup 
{
   my($fd_filename) = @_; 
   $sha1sumraw = `sha1sum $fd_filename`;
   @sha1sumsplit = split(/ /, $sha1sumraw); 
   $sha1sum = $sha1sumsplit[0]; 
   $reval = 0; 

   if ( exists($filedupsums{$sha1sum}))
   {
      $retval = 1; 
      $filedupsums{$sha1sum}++; 
   }
   else
   {
      $filedupsums{$sha1sum} = 0; 
      $retval = 0; 
   }
 
   return $retval;  
}


# Needed to avoid error when require'ing this file. 
1; 
