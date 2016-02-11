uName = ARGV.first
prompt = '> '

puts "Hi #{uName}."
puts "I have a few questions."
puts "Do you like me #{uName}? ", prompt
likes = $stdin.gets.chomp # note: stdin needed if argument passed via command line

puts "Where do you live #{uName}? ", prompt
lives = $stdin.gets.chomp

puts "What kind of computer do you have? ", prompt
computer =$stdin. gets.chomp

puts """
Alright, so you said #{likes} about liking me.
You live in #{lives}.  Not sure where that is.
And you have a #{computer} computer. Nice.
"""
