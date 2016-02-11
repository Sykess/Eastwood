
# File.open("text.txt").each { |line| puts line }

# lineCount = 0
# File.open("text.txt").each { |line| lineCount += 1 }
# puts lineCount

# text = ''
# lineCount = 0
# File.open("text.txt").each do |line|
#     lineCount += 1
#     text << line
# end
# 
# puts "#{lineCount} lines"

lines = File.readlines("text.txt")
lineCount = lines.size
text = lines.join

puts "#{lineCount} lines"
totalChars = text.length
puts "#{totalChars} characters"

# "this is a test".gsub(/t/, 'X') # Xhis is a XesX

totalCharsNospace = text.gsub(/\s+/, '').length
puts "#{totalCharsNospace} characters excluding spaces"

# puts "this is a test".scan(/\w+/).join('-') # this-is-a-test
#                                  .length # 4
# puts "this is a test".split.length # 4

wordCount = text.split.length
puts "#{wordCount} words"

sentenceCount = text.split(/\.|\?|!/).length #splits by punctuation
paragraphCount = text.split(/\n\n/).length
puts "#{paragraphCount} paragraphs"
puts "#{sentenceCount} sentences"
puts "#{sentenceCount / paragraphCount} sentences per paragraph (average)"
puts "#{wordCount / sentenceCount} words per sentence (average)"

stopwords = %w{the a by on for of are with just but and to the my I has some in}

# text = %q{Los Angeles has some of the nicest weather in the country.}
# stopwords = %w{the a by on for of are with just but and to the my in I has some}
# words = text.scan(/\w+/)
# keywords = words.select { |word| !stopwords.include?(word) }
# puts keywords.join(' ') # Los Angeles nicest weather country
all_words = text.scan(/\w+/)

good_words = all_words.select{ |word| !stopwords.include?(word) }
good_percent = ((good_words.length.to_f / all_words.length.to_f) * 100).to_i

sentences = text.gsub(/\s+/, ' ').strip.split(/\.|\?|!/)
sentences_sorted = sentences.sort_by { |sentence| sentence.length }
one_third = sentences_sorted.length / 3
ideal_sentences = sentences_sorted.slice(one_third, one_third + 1)
ideal_sentences = ideal_sentences.select { |sentence| sentence =~ /is|are/ }

puts "#{good_percent}% of words are non-fluff words"
puts "Summary:\n\n" + ideal_sentences.join(". ")
puts "-- End of analysis"

# text = %q{
# Ruby is a great programming language.  It is object oriented
# and has many groovy features.  Some people don't like it, but that's
# not our problem! It's easy to learn. It's great. To learn more about Ruby,
# visit the official Ruby Web site today.
# }
#
# sentences = text.gsub(/\s+/, ' ').strip.split(/\.|\?|!/)
# sentences_sorted = sentences.sort_by { |sentence| sentence.length }
# one_third = sentences_sorted.length / 3
# ideal_sentences = sentences_sorted.slice(one_third, one_third + 1)
# ideal_sentences = ideal_sentences.select { |sentence| sentence =~ /is|are/ }
# puts ideal_sentences.join(". ") 
# # Ruby is a great programming language.  It is object oriented and has many groovy features.




