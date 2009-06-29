
# Given input file name and command, launch two EC2 instances
# Run SmartFuzz on one instance, zzuf on the other instance 
use Net::Amazon::EC2;

# Read amazon data from environment
$aws_access_key = $ENV{AWS_ACCESS_KEY_ID}; 
$aws_secret = $ENV{AWS_SECRET};
$ec2_pk = $ENV{EC2_PRIVATE_KEY};
$ec2_cert = $ENV{EC2_CERT}; 
$ec2_keypair_name = $ENV{EC2_KEYPAIR_NAME};
$ec2_keypair_path = $ENV{EC2_KEYPAIR_PATH}; 
$mf_image = $ENV{MF_IMAGE_ID}; 

# Initialize EC2 object
$ec2 = Net::Amazon::EC2->new(
    AWSAccessKeyId => $aws_access_key,
    SecretAccessKey => $aws_secret
    ); 


# Grab the input file name and the command line to execute
# Assume the input file is in this directory 
$inputname = $ARGV[0];
$argnum = $#ARGV;

$commandline = "";
$argcount = 1; 
while ($argcount <= $argnum)
{
    $commandline = $commandline . " " . $ARGV[$argcount];
    $argcount++;
}

# Launch EC2 instances
print "Launching EC2 instances for SmartFuzz and zzuf.\n"; 
print "Image ID: $mf_image , Keypair Name: $ec2_keypair_name \n"; 
$instance_smartfuzz = $ec2->run_instances(ImageId => $mf_image, MinCount => 1, MaxCount => 1, KeyName => $ec2_keypair_name, InstanceType => "m1.large");
$instance_zzuf = $ec2->run_instances(ImageId => $mf_image, MinCount => 1, MaxCount => 1, KeyName => $ec2_keypair_name, InstanceType => "m1.large");

$smartfuzz_instId = $instance_smartfuzz->instances_set->[0]->instance_id;
$zzuf_instId = $instance_zzuf->instances_set->[0]->instance_id;


# Poll instances waiting for them to hit the "running" state
print "Waiting for SmartFuzz instance, instanceID $smartfuzz_instId .\n";
$smartfuzz_status = $instance_smartfuzz->instances_set->[0]->instance_state->code;

while ($smartfuzz_status != 16)
{
    print "SmartFuzz instance not running yet, status code: $smartfuzz_status \n"; 
    sleep(5); 
    $instance_smartfuzz = $ec2->describe_instances(InstanceId => $smartfuzz_instId)->[0]; 
    $smartfuzz_status = $instance_smartfuzz->instances_set->[0]->instance_state->code;

}

$smartfuzz_name = $instance_smartfuzz->instances_set->[0]->dns_name;
print "SmartFuzz instance running at $smartfuzz_name \n"; 

print "Waiting for zzuf instance, instanceID $zzuf_instId .\n";
$zzuf_status = $instance_zzuf->instances_set->[0]->instance_state->code;
while ($zzuf_status != 16)
{
    print "Zzuf instance not running yet, status code: $zzuf_status \n"; 
    sleep(5);
    $instance_zzuf = $ec2->describe_instances(InstanceId => $zzuf_instId)->[0];  
    $zzuf_status = $instance_zzuf->instances_set->[0]->instance_state->code;
}

$zzuf_name = $instance_zzuf->instances_set->[0]->dns_name;
print "Zzuf instance running at $zzuf_name \n"; 

# Add extra delay to make sure sshd has time to come up
# Otherwise can happen that instance is running but won't accept connections
# Should poll and catch when that happens but this works for now
sleep(7); 

print "Copying $inputname to SmartFuzz instance. \n";
system("scp -o StrictHostKeyChecking=no -i $ec2_keypair_path $inputname root@" . $smartfuzz_name . ":"); 

print "Copying $inputname to Zzuf instance. \n";
system("scp -o StrictHostKeyChecking=no -i $ec2_keypair_path $inputname root@" . $zzuf_name . ":"); 

print "Starting SmartFuzz on SmartFuzz instance \n"; 
$smartfuzz_start = "ssh -o StrictHostKeyChecking=no -i $ec2_keypair_path root@" . $smartfuzz_name ." \"source /root/vgcc/bin/cc_envars && nohup docatchconv $inputname $commandline >& output-docatchconv-$inputname & \" &";
print "Command: $smartfuzz_start \n"; 
system($smartfuzz_start);

print "Starting Zzuf on Zzuf instance \n"; 
$zzuf_start = "ssh -o StrictHostKeyChecking=no -i $ec2_keypair_path root@" . $zzuf_name . " \"source /root/vgcc/bin/cc_envars && nohup dozzuf $inputname $commandline >& output-dozzuf-$inputname & \" &"; 
print "Command: $zzuf_start \n";
system($zzuf_start); 

print "Finished starting SmartFuzz and Zzuf for input file $inputname with command line $commandline !\n"; 
