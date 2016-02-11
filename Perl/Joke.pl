#!/usr/bin/perl -w
#
#Joke.pl

clear_the_screen();

$reply = "";

while($reply ne 'yes'){
    print 'Would you like to hear a joke? (yes/no): ';
    chomp($reply = <STDIN>);

    if($reply ne 'yes')
    {
        print "\nHmm, perhaps you misunderstood.\n\n";
    }
}

clear_the_screen();

print "\nWhat disappears the moment you say its name?";
chomp($reply = <STDIN>);

if($reply ne 'silence'){
    print "\nSorry. Wrong answer.  Think about it and try again later.\n\n";
}   else{
    print "\nYes, that is right. Well done!\n\n";
}

sub clear_the_screen {
    for ($i=0; $i < 25; ++$i){
        print "\n";
    }
}
