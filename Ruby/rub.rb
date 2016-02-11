class Person
    attr_accessor :name, :age, :gender
end

class Pet
    attr_accessor :name, :age, :gender, :color
end

class Cat < Pet
end

class Dog < Pet
    def bark
        puts "Woof!"
    end
end

# can use 2 object and + method in place of 2 + 2
class TwoPlusTwo
    def add
        puts 2.+(2)
    end
end

def dog_barking
    puts "Woof!"
end

class Snake < Pet
    attr_accessor :length
end


' multi line comment syntax (can also use 3 ''s)
spot = Dog.new
spot.bark
dog_barking
Object.dog_barking # doesnt work
puts dog_barking.class # Nil class
puts spot.class
puts 2.class
Kernel.puts "hello" #explicit call to puts
puts "Testing length".length # prints 14
puts "Testing length".upcase # changes all chars to uppercase
puts "test".capitalize # Test
puts "Test".downcase # test
puts "Test".chop # Tes
puts "Test".next # Tesu (increases last letter)
puts "Test".reverse # tseT
puts "Test".sum # 416
puts "Test".swapcase # tEST
puts "Test".upcase # TEST
puts "Test".upcase.reverse # TSET
puts "Test".upcase.reverse.next # TSEU
'



