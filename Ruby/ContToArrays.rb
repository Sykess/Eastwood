
# x = [1,2,3,4] # array
# puts x[2] # 3
# x[2] += 1
# puts x[2] # 4
# x[2] = "Fish" * 3
# puts x[2] # FishFishFish
#
# x = [] #empty, accessing x[5] would result in nil
# x << "Word" # push Word into array
# x.push("Word") # equivalent to ^
#
# x = []
# x << "Word"
# x << "Play"
# x << "Fun"
# puts x.pop # Fun (LIFO system, like stack)
# puts x.pop # Play
# puts x.length # 1 (note x.size results same)
#
# x = ["Word", "Play", "Fun"]
# puts x.join # WordPlayFun
# puts x.join(', ') # Word, Play, Fun
#
# puts "This is a test".scan(/\w/).join(',') # T,h,i,s,i,s,a,t,e,s,t
# puts "Short sentence. Another. No more.".split(/\./).inspect # ["Short sentence", " Another", " No more"]
# note inspect gives texual representation of the object
#
# puts "Words with lots of spaces".split(/\s+/).inspect # ["Words", "with", "lots", "of", "spaces"]
# p "Words with lots of spaces".split(/\s+/) # another way to do ^^  p is useful for debugging
#
# [1, "test", 2, 3, 4].each { |element| puts element.to_s + "X" } # 1X testX 2X 3X 4X (each goes through each element)
# [1, 2, 3, 4].collect { |element| element * 2 } # [2, 4, 6, 8] (collect iterates and assigns element result of expression)
# note map is functionally equivalent to collect
#
# a = [1, "test", 2, 3, 4]
# i = 0
# while (i < a.length)
#   puts a[i].to_s + "X"
#   i += 1
# end  # the "old-fashioned" way of iterating and adding X, equivalent to above
#
# x = [1, 2, 3]
# y = ["a", "b", "c"]
# z = x + y
# p z # [1, 2, 3, "a", "b", "c"] (could also have used puts z.inspect)
#
# x = [1, 2, 3, 4, 5]
# y = [1, 2, 3]
# z = x - y
# p z # [4, 5]
#
# x = []
# puts "x is empty" if x.empty? # could also check if array.size or array.length is > 0
#
# x = [1, 2, 3]
# p x.include?("x") # false
# p x.include?(3) # true
# puts x.first # 1
# puts x.last # 3
# puts x.first(2).join("-") # 1-2
# p x.reverse # [3, 2, 1]
# puts x.reverse # displays 3 2 1 on separate lines instead of texual form
#
# dictionary = { 'cat' => 'feline animal', 'dog' => 'canine animal' } # called a hash, no guaranteed order
# puts dictionary.size # 2
# puts dictionary['cat'] # feline animal
# dictionary['cat'] = "Fluffy animal"
# puts dictionary['cat'] # fluffy animal
#
# x = { "a" => 1, "b" => 2 }
# x.each { |key, value| puts "#{key} equals #{value}" } # a equals 1   b equals 2
# p x.keys # ["a", "b"] (values instead of keys will display the values)
# x.delete("a")
# p x # {"b"=>2}
#
# x = { "a" => 100, "b" => 20 }
# x.delete_if { |key, value| value < 25 }
# p x # {"a"=>100}
#
# people = { 'fred' => { 'name' => 'Fred Elliott', 'age' => 63, 'gender' => male', 'fav painters' => ['Money', 'Da Vinci'] },
#   'janet' => { 'name' => 'Janet S Porter', 'age' => 55, 'gender' => 'female' } }
# puts people['fred']['age'] # 63
# puts people['janet']['gender'] # female
# p people['janet'] # {"name"=>"Janet S Porter", "Gender"=>"female", "age"=>55}
# puts people['fred']['fav painters'].join(", ") # Money, Da Vinci
#
# age = 10
# if age < 18
#   puts "You're too young!"
# end  # same as puts "You're too young!" if age < 18
#
# if age < 18
#   puts "You're too young!"
# else
#   puts "You can use it!"
# end # can use if/else, or unless/else
#
# type = age < 18 ? "child" : "adult"
# puts "You are a " + type
#
# fruit = "orange"
# if fruit == "orange"
#   color = "orange"
# elsif fruit == "apple"
#   color = "green"
# else
#   color = "unknown"
# end
#
# case fruit
#   when "orange"
#   color = "orange"
#   when "apple"
#   color = "green"
#   else
#   color = "unknown"
# end
#
# color = case fruit
#   when "orange"
#   "orange"
#   when "apple"
#   "green"
#   else
#   "uknown"
# end
#
# x = 1
# while x < 100 # until can be substitued for while
#   puts x
#   x = x * 2
# end
#
# i = 1
# i = 1 * 2 until i > 1000
# puts i # 1024
#
# x = [1, 2, 3]
# x.each { |y| puts y } # 1 2 3  (can use do end for multi lines)
#
# def each_vowel(&code_block)
#   %w{a e i o u}.each { |vowel| code_block.call(vowel) }
# end
# each_vowel { |vowel| puts vowel } # a e i o u  (& means accepts code block)
#
# def each_vowel
#   %w{a e i o u}.each { |vowel| yield vowel }
# end
# each_vowel( |vowel| puts vowel} # same as previous
#
# print_param_to_screen = lambda { |x| puts x } # stores code block within variable
# print_param_to_screen.call(100) # 100 (lambdas can be called code blocks, or sometimes referred to as Procs)
#
# puts Time.now # Thu Apr 16 00:00:00 +0100 2009
# puts Time.now - 10 # subtracts 10 seconds
# puts Time.now + 86400 # adds 1 day worth of seconds
#
class Fixnum
    def seconds
        self
    end
    def minutes
        self * 60
    end
    def hours
        self * 60 * 60
    end
    def days
        self * 60 * 60 * 24
    end 
end
# puts Time.now
# puts Time.now + 10.minutes
# puts Time.now + 16.hours
# puts Time.now + 7.days
#
# Time.local(year, month, day, hour, min, sec, msec) # creates time based current time zone.  Month onward are optional
# Time.gm(same as ^^) # sets time based on GMT/UTC  Can also use Time.utc("")
# Time.gm(2007, 05).to_i # gives seconds - 1177977600
# epoch_time = Time.gm(2007, 5).to_i
# t = Time.at(epoch_time)
# puts t.year, t.month, t.day # 2007 5 1
#
# riceOnSquare = 1
# 64.times do |square|
#   puts "On square #{square+1} are #{riceOnSquare} grain(s)"
#   riceOnSquare *= 2
# end # really large numbers
#
