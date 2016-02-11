
require 'set'
colors1 = Set.new( [ :red, :green, :blue ] )
colors2 = Set.new( [ :brown, :yellow, :red ] )
colors1 | colors2 # combines 2 sets into union
colors2 & colors1 # what is common between the 2
colors1 - colors2 # green, blue
colors1 ^ colors2 # all except common

def fixed_array(size, otherArr = [])
    Array.new(size) { |i| otherArr[i] }
end

def fill_array(size, fill)
    Array.new(size) { |i| fill }
end

# puts fixed_array(5, [1, 2, 3])
arr = fixed_array(5)
arr.push(5)
# print "arr length: ", arr.length, "\n"


# puts fill_array(5, 0) # fills 5 elements with 0


def call_block
    puts "Start method"
    yield
    yield
    puts "End of method"
end

call_block { puts "In the block" } # yields will display "In the block"


$:.each { |d| puts d }



