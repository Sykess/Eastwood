
# ls = IO.popen("ls", "r")
# while line = ls.gets
#     puts line
# end
# ls.close # this block call ls and prints its conents line by line

while x = gets
    puts "=> #{eval(x)}"
    print ">"
end





