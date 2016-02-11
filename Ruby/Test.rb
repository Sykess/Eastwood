
class Test
    def initialize(name)
        @name = name
    end

    #attr_reader :name # readers can only "get", writers can only "set" and accessors can do both
    attr_accessor :name

    def name=(value)
        @name = value
    end
end

blah = Test.new("Nate")
blah.name = "bob"
puts blah.name

Member = Struct.new(:name, :country)
cody = Member.new("Cody B", "Ireland")
raj = Member.new("Raj C", "United States")
kim = Member.new("Kim C", "Hell")
puts cody.name
puts kim.country
puts kim.name
puts Member.members
puts cody == kim
kim.each { |x| puts (x) }

nums = {"kim"=>"7765", "nate"=>"8529"}
puts nums.keys
puts nums.values

grades = 0..100 # make range 0-100
blah = grades.reject { |grade| grade < 60 } # reject will ignore the values under 60 here
# blah.each do |num|
#     print num, " "
# end

(1..10) === 5 # is 5 in interval 1-10? true
(60..100) === 74.25 # true

numbers = (1..10).to_a # to array


module Weather
    def self.ftoc(f)
        return (5.0 / 9.0) * (f - 32.0)
    end
    def self.ctof(c)
        return (9.0 / 5.0) * c + 32.0
    end
    PI = 3.14159
end

puts Weather.ftoc(32)
puts Weather.ctof(100)
puts Weather::PI


