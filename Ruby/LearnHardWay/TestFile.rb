filename = ARGV.first

puts "We're going to erase #{filename}"
puts "If you don't want that, hit Ctrl-c."
puts "If you do, hit enter."
$stdin.gets

puts "Opening the file..."
target = open(filename, 'w')

puts "Truncating the file, goodbye!"
# target.truncate(0)

puts "Now I need 3 lines"
print "Line 1: "
line1 = $stdin.gets.chomp
print "Line 2: "
line2 = $stdin.gets.chomp
print "Line 3: "
line3 = $stdin.gets.chomp

puts "Now time to write to file."
target.write(line1)
target.write("\n")
target.write(line2)
target.write("\n")
target.write(line3)
target.write("\n")

puts "And finally, close the file"
target.close
