
# Lambdas used with the reduce function to make a factorial function:

def fact(x):
    f = lambda x,y: x*y
    return reduce(f, range(1,x+1))

