
failures = []
failures.append("/home/nate/me")
failures.append("/home/second/blah")
failures.append("failures/more")
failures.append("/last/one")
failures.append("/home/nate/boo/you")
failures.append("/home/second/boo/ya")

for i in failures:
    i = i.replace('/home/nate', '*').replace('/home/second', '*').replace('boo', 'blue')
    print i

file = open("/home/nathan.caron/Documents/Learning/Python/failures.txt", "w")
for i in failures:
    file.write("%s\n" % i)
