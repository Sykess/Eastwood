
def farey(n, asc=True):
    if asc:
        a,b,c,d = 0,1,1,n
    else:
        a,b,c,d = 1,1,n-1,n
    count = 0
    start = False

    print "%d/%d" % (a,b)
    while(asc and c<=n) or (not asc and a > 0):
        k = int((n + b)/d)
        a,b,c,d = c,d,k*c-a, k*d-b
#         print "%d/%d" % (a,b)
        if a == 1 and b == 3:
            start = True
        if a == 1 and b == 2:
            start = False
        if start:
            count += 1
    return count - 1

print farey(12000)
