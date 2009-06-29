
$mplayer = "/work/dmolnar/mplayer-svn/inst/bin/mplayer"; 
$core = @ARGV[0]; 
$bugreport = "report-$core"; 
system("echo \"Catchconv report for mplayer core file \'$core\' \" > $bugreport");  
system("echo \"\nGDB session output: \n \" >> $bugreport"); 
system("gdb $mplayer --core=$core -batch --command=mp_gdb >> $bugreport"); 

system("echo \"\nSystem information (uname, libc, etc.)\n\" >> $bugreport"); 
system("echo \"\nuname -a:\n\" >> $bugreport"); 
system("uname -a >> $bugreport"); 
system("echo \"\nlibc version:\n\" >> $bugreport"); 
system("ls -l /lib/libc[.-]* >> $bugreport"); 
system("echo \"\ngcc, ld, as versions:\n\" >> $bugreport"); 

system("gcc -v 2>> $bugreport"); 
system("ld -v >> $bugreport"); 
system("as --version >> $bugreport");
system("echo \"\nCPU info:\n\" >> $bugreport");  
system("cat /proc/cpuinfo >> $bugreport"); 
