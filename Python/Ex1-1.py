
def CtoF(c):
    return c * 9 / 5 + 32
def FtoC(f):
    return (f - 32) * 5/9

cel = raw_input("Enter degrees in Celsius:")
# cel = int(cel)
# print "The value of cel is:",cel, "and is type", type(cel)
try:
    far = CtoF(float(cel))
    print cel, "degrees celsius is", far, "degrees fahrenheit"
except:
    print "You did enter a valid number"
far = raw_input("Enter degrees in Fahrenheit:")
try:
    cel = FtoC(float(far))
    print far, "degrees fahrenheit is", cel, "degrees celsius"
except:
    print "You did not enter a valid number"
