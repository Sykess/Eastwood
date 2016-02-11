
#puts "a" + "b" + "c"
#puts 100 - 5 * (2 - 1)
#age = 10
#puts "You're too young!" if age < 18
#puts "Aha you're 10!" if age == 10
#puts "You're a teenager! " if age > 12 && age < 20
# x <=> y #returns 0 if equal, 1 if x higher, -1 if y higher
#
#5.times do puts "test" end # prints "test" 5 times (5 calls times method with code between do-end as param)
#5.times { puts "test" } # does same as ^^
#1.upto(5) { code } # iterates
#10.downto(5) { code } #iterates
#0.step(50, 5) { code } #iterates 0-50 by 5's
#1.upto(5) { |number| puts number } # prints number of iterator (1-5)
#
#1.upto(5) do |number|
#  puts number
#end  # can spread across multi lines with do and end
#
#x = 10
#y = 3
#puts x.to_f / y.to_f # converts to floats to get 3.333333
#
#Pi = 3.141592 # declare as constant, can change such as Pi = 500, but will get warning
#
#puts "Hello!".class # String
#x = "Test"
#y = "String"
#puts "Success!" if x + y == "TestString" # will print!
#
#x = %q{This is a
#multi line
#string}  # note the { is optional and can be anything such as <>, (), or !!
#
#x = <<END_MY_STRING
#This is the string
#And a second line
#END_MY_STRING # using a "here" document also works
#
#puts "abc" * 5 # abcabcabcabcabc
#
#puts "x" > "y" # false
#puts "y" > "x" # true
#
#puts ?x # 120 (the ascii value)
#puts ?A # 65
#puts 120.chr # x
#puts 65.chr # A
#
#x = 10
#y = 20
#puts "#{x} + #{y} = #{x + y}" # 10 + 20 = 30
#puts "100 * 5 = #{100 * 5}" # 100 * 5 = 500
#
#x = "cat"
#puts "The #{x} in the hat" # The cat in the hat
#puts "It's a #{"bad " * 5}world" # It's a bad bad bad bad bad world
#my_string = "It's a #{"bad " * 5}world"
#
#x = 10
#y = 20
#puts x.to_s + " + " + y.to_s + " = " + (x + y).to_s #outputs same as above 10 + 20 = 30
#
#puts "foobar".sub('bar', 'foo') # subs bar with foo, producing foofoo
#puts "this is a test".gsub('i', '') # ths s a test (note sub only does 1 sub, gsub does many)
#
#x = "This is a test"
#puts x.sub(/^../, 'Hello') # Hellois a test (subs first 2 letters with 'Hello')
#puts x.sub(/..$/, 'Hello') # This is a teHello (subs last 2)
#
#"xyz".scan(/./) { |letter| puts letter } # scans through and prints each letter
#"This is a test".scan(/../) { |x| puts x } # prints 2 letters per line, including whitespace)
#
#"This is a test".scan(/\w\w/) { |x| puts x } # only prints letters and digits(skips a since surrounded by spaces)
#
# ^-begin line  $-end line  \A-start string  \Z-end string  .-any char  \w-any letter,digit, or underscore
# \d-any digit  \D-anything \d doesn't match  \s-whitespaces, tabs, newlines  \S-any visible character
# +-1 or more, as many as possible  *-0 or more, as many as possible  *?-0 or more, few as possible
# +?-1 or more, few as possible  ?-match 1 or none  {x}-match x occurances  {x,y}-match at least x, at most y
#
# "The car costs $1000 and the cat costs $10".scan(/\d+/) do |x| puts x end  #prints 1000 one line, 10 next
#
# "This is a test".scan(/[aeiou]/) { |x| puts x } # i i a e
#
# "This is a test".scan(/[a-m]/) { |x| puts x } # h i i a e
#
# puts "String has vowels" if "This is a test" =~ /[aeiou]/ # =~ is matching operator, will return position of first match
# puts "String contains no digits" unless "This is a test" =~ /[0-9]/ # checks for numbers
#
# x = "This is a test".match(/(\w+) (\w+)/)
# puts x
# puts x[0] #This is (entire expression)
# puts x[1] #This
# puts x[2] #is
#
#



