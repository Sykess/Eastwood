
valid = false
until valid
    print "How are you? "
    var = $stdin.gets.chomp
    valid = true if var == "Stop" || var == "Fine"
    break if var == "Break"
end





