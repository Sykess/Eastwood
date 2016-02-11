

# File.open("text.txt").each { |line| puts line }
# f = File.new("text.txt", "r").each { |line| puts line } # does same as ^^(r is for reading, and is default)
# f.close # need to close with new, open does it implicitly

# puts Dir::pwd # can use to see current directory


class MyFile
    attr_reader :handle
    def initialize(filename)
        if File.exist?(filename)
            @handle = File.new(filename, "r")
        else
            return false
        end
    end

    def finished
        @handle.close
    end
end
# f = MyFile.new("text.txt")
# puts f.handle.gets
# f.finished

# File.open("dummy.txt").each(',') { |line| puts line } # uses , as delim instead of newline
# File.open("dummy.txt").each_byte { |byte| puts byte } # note: can use byte.chr for chars 
# File.open("dummy.txt").each_char { |byte| puts byte }

# File.open("dummy.txt") do |f|
#     2.times { puts f.gets }
# end
# File.open("dummy.txt") do |f|
#     2.times { puts f.gets(',') }
# end
# File.open("dummy.txt") do |f|
#     2.times { puts f.getc } # getc is similar to each_byte
# end

# puts File.open("dummy.txt").readlines.join("--")
# File.open("dummy.txt") { |f| puts f.read(6) } # read(6) means read 6 bytes

data = File.read("dummy.txt")
array_of_lines = File.readlines("dummy.txt")

# puts "data: ", data, "array: ", array_of_lines[0]

# f = File.open("dummy.txt")
# puts f.pos # position within file (bytes from start of file)
# puts f.gets
# puts f.pos
# f.pos = 8 # set position to 8
# puts f.gets
# puts f.pos
#
# f.close

# File.open("dummy2.txt", "w") { |f| f.puts "This is a test" }#writes single line to file 
# File Modes usable with File.new:
# r - read only, r+ - read and write, w - write only (create file or overwrite existing)
# w+ - read and write, but creates new file or overwrites existing
# a - write in append mode, file pointer placed at end of file, a+ - same as a but can read
# b - binary mode, can be used in conjunction with other modes

f = File.new("logfile.txt", "a") # append mode example
f.puts Time.now
f.close

# f = File.open("dummy2.txt", "r+")
# puts f.gets
# f.puts "This is a test"
# puts f.gets
# f.close

# f = File.open("dummy2.txt", "r+")
# f.putc "X" # Overwrites first letter with X
# f.write "123456"# Overwrites next 6 letters with 123456
# f.close

# File.new("text.txt", "r:utf-8").each { |line| puts line } # ruby 1.9+ selects utf-8 encoding scheme
# puts File.open("text.txt", "r:utf-8").external_encoding # determine encoding(req ruby 1.9+)
# puts File.open("text.txt", "r").external_encoding # ^^
# File.rename("file1.txt", "file2.txt")
# File.delete("file1.txt")
# File.delete("file2.txt", "file3.txt", "file4.txt")
# File.unlink("file1.txt") # same thing as file.delete

# File.join('full', 'path', 'here', 'filename.txt') # windows full\path\here\filename.txt, linux full/path/here/filename.txt
# File.join(File::SEPARATOR, 'full', 'path', 'here', 'filename.txt') # adds leading / or \

# puts File.expand_path("dummy2.txt") # expands to full path

# f = File.new("dummy2.txt", "r+")
# f.seek(-5, IO::SEEK_END) # SEEK_CUR goes forward from cur position, SEEK_SET is same as pos=
# f.putc "X" # puts X in spot 5 bytes from end of file
# f.close

# f = File.new("dummy2.txt", "r")
# while a = f.getc
#     puts a.chr
#     f.seek(5, IO::SEEK_CUR)
# end # prints every 5th char (aka byte)
# f.close

# puts File.mtime("dummy2.txt") # displays when file was last modified
# t = File.mtime("dummy2.txt") # time is returned as Time object
# puts t.hour
# puts t.min
# puts t.sec

# puts "It exists!" if File.exist?("dummy2.txt")

# puts File.size("dummy2.txt") # size in bytes, throws exception if file doesn't exist

# f = File.new("dummy2.txt", "r")
# catch(:end_of_file) do
#     loop do
#         throw :end_of_file if f.eof?
#         puts f.gets
#     end # uses infinite loop that breaks when end of file is reached
# end
# f.close

# Dir.chdir("/usr/bin") # change directory
# puts Dir.pwd # prints current directory
# puts Dir.entries("/usr/bin").join(' ') # list of files and directories within /usr/bin
# Dir.foreach("/usr/bin") { |entry| puts entry } # same as entries but with iterator instead of array
# Dir["/usr/bin/*"] # Dir's class array method (entries returned as absolute filename
# Dir[File.join(File::SEPARATOR, 'usr', 'bin', '*')] # ^^ but platform independant
# Dir.mkdir("/mynewdir") # make directory
# Dir.delete("mynewdir") # delete directory (Dir.unlink and Dir.rmdir do same)
# Note if directory is not empty, must iterate through subdirs first, cand o with Dir.foreach
# Alternatively, can use rm_f
# require 'fileutils'
# FileUtils.rm_f(directory_name) # caution not to delete wrong thing

# require 'tmpdir'
# puts Dir.tmpdir # shows temporary directory program can use

require 'csv'
# CSV.open('dummy.txt', 'r').each do |person|
#     puts person.inspect
# end
# people = CSV.parse(File.read('dummy.txt'))
# puts people[0][0], people[1][0], people[2][0]

# puts CSV.read('dummy.txt').inspect

# people = CSV.read('dummy.txt')
# laura = people.find { |person| person[0] =~ /Laura/ } #detect does same as find, select same as find_all
# puts laura.inspect

# young_people = people.select do |p|
#     p[3].to_i.between?(20, 40)
# end
# puts young_people.inspect

# people = CSV.read('dummy.txt')
# laura = people.find { |person| person[0] =~ /Laura/ }
# laura[0] = "Lauren Smith"
# 
# CSV.open('dummy.txt', 'w') do |csv|
#     people.each do |person|
#         csv << person
#     end
# end

class Person
    attr_accessor :name, :job, :gender, :age
end

fred = Person.new
fred.name = "Fred Bloggs"
fred.age = 45
laura = Person.new
laura.name = "Laura Smith"
laura.age = 23
require 'pstore'
# store = PStore.new("storagefile")
# store.transaction do
#     store[:people] ||= Array.new
#     store[:people] << fred
#     store[:people] << laura
# end

# Now to retrieve data from PStore db:
# store = PStore.new("storagefile")
# people = []
# store.transaction do
#     people = store[:people]
# end
# people.each { |person| puts person.name }

require 'yaml'

# test_data = [ fred, laura ]
# puts YAML::dump(test_data)
yaml_string = <<END_DATA
---
- !ruby/object:Person
  age: 45
  name: Jimmy
- !ruby/object:Person
  age: 23
  name: Laura Smith
END_DATA

# test_data = YAML::load(yaml_string)
# puts test_data[0].name
# puts test_data[1].name

















