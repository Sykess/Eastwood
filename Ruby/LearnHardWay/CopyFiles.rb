
fromFile, toFile = ARGV

puts "Copying from #{fromFile} to #{toFile}"

indata = open(fromFile).read

puts "The input file is #{indata.length} bytes long"

puts "Does the output file exist? #{File.exist?(toFile)}"
puts "Ready, hit enter to continue, ctrl-c to abort."
$stdin.gets

outFile = open(toFile, 'w')
outFile.write(indata)

puts "All done!"
outFile.close

