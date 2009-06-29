$filename = $ARGV[0];
$prefix = $ENV{CC_PREFIX}; 
$suffix = (split(/\./, $filename))[1];

if (!($suffix eq ""))
{
   if (-e "$prefix/bin/singlemachine-$suffix.pl")
   {
      $newcommand = "$prefix/bin/singlemachine-$suffix.pl $filename"; 
      exec("perl $newcommand");
   }
   else
   {
      print "I don't have a handler for the extension $suffix !\n"; 
      print "Please write a script called '$prefix/bin/singlemachine-$suffix.pl' to tell me what to do with this kind of file.\n"; 
      print "Alternatively, run 'perl $prefix/bin/docatchconv.pl <inputfile> <command_line> directly. \n"; 
   }  
}
else
{
    print "I don't know what kind of file this is or what to do with it!\n"; 
    print "If you know what program you want to run on this file, please run the command line 'perl $prefix/bin/docatchconv.pl <inputfile> <command_line>' \n"; 
}
