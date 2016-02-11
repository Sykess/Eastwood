# filename = ARGV.first
# 
# txt = open(filename)
# 
# puts "Here's your file #{filename}:"
# print txt.read
# txt.close()

print "Type the filename again: "
fileAgain = $stdin.gets.chomp

txtAgain = open(fileAgain)

print txtAgain.read
txtAgain.close()
