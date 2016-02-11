#!/bin/bash

# printf options:
# Escape sequences: \a: alert (bell), \b: backspace, \e: escape character, \f: form feed
#                   \n: newline, \r: carriage return, \t: horizontal tab, \v: vertical tab
#                   \\: backslash, \nnn: special char 1-3 octal digits, \xHH: << but hex
#                   ex: \141 prints a (octal ascii) \x42 prints B (hex ascii)
# Format specifiers: %s: prints literal chars in the argument
#                    %b: same except escape sequences are translated 
#                    %d: prints integer, for octal leading 0, hex leading 0x (2.4 invalid)
#                    %f: prints float by default to six decimal places
#                    %e: exponential (scientific notation)
#                    %x and %X: print integer in Hex (x for lowercase, X for uppercase)
#                    %#s: # specifies width, positive is flush right, negative flush left
#                        if # starts with 0, numbers are padded with leading 0's
#                        a decimal specifies precision of float, or max width of string
# \ at end of line continues line without a newline

# printf "%s\n" Print arguments on "separate lines"
# printf "%b\n" "Hello\nthere" "12\tword"
# printf "%d\n" 23 45 56.86 0xff 011 
# printf "%f\n" 12.34 23 56.789 1.2345678
# printf "%e\n" 12.34 23 56.789 123.45678 1.23
# printf "color: #%02x%02X%02X;\n" 65 105 225
# printf "%8s %-15s:\n" first second thi fourth fifth six
# printf "%04d\n" 12 23 56 123 255 12345
# printf "%12.4s %9.2f\n" John 2 Jackson 4.567 Walter 2.9

# printf -v num4 "%04d" 4 # -v option stores output in variable
# printf "%s\n" "$num4"






