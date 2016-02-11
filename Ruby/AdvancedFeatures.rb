
eval "puts 2 + 2"

my_num = 15
my_code = %Q{#{my_num} * 2}
puts eval(my_code) # 30

def binding_elsewhere
    x = 20
    return binding
end

remote_binding = binding_elsewhere
x = 10
eval("puts x")
eval("puts x", remote_binding)

class Person
end
def add_accessor_to_person(accessor_name)
    Person.class_eval %Q{
        attr_accessor :#{accessor_name}
    }
end

person = Person.new
add_accessor_to_person :name
add_accessor_to_person :gender
person.name = "Bob Joe"
person.gender = "Male"
puts "#{person.name} is #{person.gender}"

class Class
    def add_accessor(accessor_name)
        self.class_eval %Q{
            attr_accessor :#{accessor_name}
        }
    end
end # extends class so you can add accessors to any class made
class Bleh
end
bleh = Bleh.new
Bleh.add_accessor :name
Bleh.add_accessor :blue
bleh.name = "yeah"
bleh.blue = "red"
class AnotherClass
    add_accessor :whatever # will work up to base class Class, where we made add_accessor
end

class Class
    def add_accessor(accessor_name)
        self.class_eval %Q{
            def #{accessor_name}
                @#{accessor_name}
            end

            def #{accessor_name}=(value)
                @#{accessor_name} = value
            end
        }
    end
end # this code is basically what attr_accessor does!






