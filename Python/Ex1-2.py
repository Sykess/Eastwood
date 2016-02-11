
text = raw_input("Enter a string:")
print "The first char is:", text[0], "and the last char is:", text[-1]

words = text.split()
print "The first word is:", words[0]
print "The first word is:", text[: text.find(' ')]

if ((text[0] == text[4]) and (text[1] == text[3])):
    print "The first 5 chars are a palindrome!"
