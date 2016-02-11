
class Square
    # @ denotes object variable
    def initialize(side_length)
        @side_length = side_length # note Ruby implicitly returns result of last statement if no return statement provided
    end
# Note this code below is for a separate Square class
#     def initialize
#         if defined?(@@number_of_squares) # @@ denotes class variable
#             @@number_of_squares += 1
#         else
#             @@number_of_squares = 1
#         end
#         #could instead use: @@number_of_squares = defined?(@@number_of_squares) ? @@number_of_squares + 1 : 1
#
#     end
# 
#     def self.count
#         @@number_of_squares
#     end

    def self.test_method # self represents the current class, without it methods are auto instance methods
        puts "Hello from square class!"
    end
#     def Square.test_method  # This is same as using self
#         puts "Hello from square class!"
#     end

    def test_method
        puts "Hello from an instance of class Square!"
    end

    def area; @side_length * @side_length end # possible to put all on one line, ; before end optional
    
end

a = Square.new(10)
b = Square.new(5)
# puts a.area, b.area
# a.test_method
# Square.test_method

def basic_method
    x=50; puts x
end

# x = 10
# basic_method
# puts x #just demonstrates scope

def basic_method
    puts $x
end

# $x = 10 # $ before variable makes it global
# basic_method

class Person
    def initialize(name)
        @name = name
    end
    def name
        @name # or return @name
    end
end
class Doctor < Person
    def name
        "Dr. " + super
    end
end

bob = Doctor.new("Who")
# puts bob.name

# class String # You can overwrite anything, and now "a".length will result in 20!
#     def length
#         20
#     end
# end

# a = "This is a test"
# puts a.methods.join("\n") # note '\n' doesn't work, literally joins with \n characters
# the methods method on any object returns an array of methods available by the object

# class Person
#     attr_accessor :name, :age
# end
# p = Person.new
# p.name = "Bob"
# p.age = 27
# puts p.instance_variables # ["@age", "@name"] (Ruby 1.9 returns symbols rather than strings)

class Person
    def initialize(name)
        set_name(name)
    end

    def name
        @first_name + ' ' + @last_name
    end

    def this_is_private
        puts "blah"
    end
    def this_is_also_private
        puts "blah"
    end

    private

    def set_name(name)
        first_name, last_name = name.split(/\s+/)
        set_first_name(first_name)
        set_last_name(last_name)
    end

    def set_first_name(name)
        @first_name = name
    end

    def set_last_name(name)
        @last_name = name
    end

    public
    
    def another_public_method
        puts "I'm public"
    end

    private :this_is_private, :this_is_also_private # another way to set privates, must be after definition
end

class Person
    def initialize(age)
        @age = age
    end
    def age
        @age
    end
    def age_difference_with(other_person)
        (self.age - other_person.age).abs
    end
    protected :age
end # Using protected, you can compare 2 instances of Person class with age_difference_with

class Animal
    attr_accessor :name

    def initialize(name)
        @name = name
    end
end
class Cat < Animal
    def talk
        "Meaow"
    end
end
class Dog < Animal
    def talk
        "Woof"
    end
end

animals = [Cat.new("Kitty"), Dog.new("Doggy")]
# animals.each do |animal|
#     puts animal.talk
# end

class Drawing
    def Drawing.give_me_a_circle
        Circle.new # From within class, inner class Circle can be called directly
    end

    class Line
    end
    class Circle
        def what_am_i
            "This is a circle"
        end
    end
end
# a = Drawing.give_me_a_circle
# puts a.what_am_i
# a = Drawing::Circle.new
# puts a.what_am_i
# a = Circle.new # error! uninitialized constance Circle

def random
    rand(10000000)
end
# puts random # displays random number between 0 and 999999

# puts (rand(26) + 65).chr # displays random capital letter

# require 'number_stuff' # file called number_stuff.rb
# require 'letter_stuff'
module NumberStuff
    def self.random
        rand(1000000)
    end
end

module LetterStuff
    def self.random
        (rand(26) + 65).chr
    end
end
# puts NumberStuff.random
# puts LetterStuff.random

module Toolbox
    class Ruler
        attr_accessor :length
    end
end

module Country
    class Ruler
        attr_accessor :name
    end
end
a = Toolbox::Ruler.new
a.length = 50
b = Country::Ruler.new
b.name = "Ghengis Khan"
include Country #can access Country's ruler class directly
c = Ruler.new
c.name = "King Henry"

module UsefulFeatures
    def class_name
        self.class.to_s
    end
    def do_stuff
        puts "Testing"
    end
end

class People
    include UsefulFeatures
end
x = People.new
# puts x.class_name
# include UsefulFeatures
# do_stuff # Testing
# UsefulFeatures.do_stuff # same

# [1,2,3,4,5].each { |number| puts number }
my_array = %w{this is a test of the longest word check}
longest_word = ''
my_array.each do |word|
    longest_word = word if longest_word.length < word.length
end
# puts longest_word # longest

my_array = %w{10 56 92 3 49 588 18}
highest_number = 0
my_array.each do |number|
    number = number.to_i
    highest_number = number if number > highest_number
end
# puts highest_number # 588

class AllVowels
    include Enumerable# by adding this can use collect, detect, select, sort, max, min on AllVowels objects

    @@vowels = %w{a e i o u}
    def each
        @@vowels.each { |v| yield v}
    end
end
x = AllVowels.new
x.collect { |i| puts i + "x"} # ["ax", "ex", "ix", "ox", "ux"]

# <=> returns -1 if left is less than right, 0 if equal, 1 if greater.  

class Song
    include Comparable

    attr_accessor :length
    def <=>(other)
        @length <=> other.length
    end

    def initialize(song_name, length)
        @song_name = song_name
        @length = length
    end
end
# a = Song.new('Rock around the clock', 143)
# b = Song.new('Bohemian Rhapsody', 544)
# c = Song.new('Minute Waltz', 60)
# now can use following thanks to Comparable: <, >=, >, between? (a.between?(c,b)) 




