#!/bin/bash

# Pi calculation: tan(pi/4) = 1
#                 atan(1) - pi/4
#                 pi = 4*atan(1)

# echo -n "Angle in degrees: "
# read deg

deg=90


pi=`echo "4*a(1)" | bc -l`
rad=`echo "$deg*($pi/180)" | bc -l`

echo "$deg Degrees = $rad Radians"

echo -n "Sin($deg): "
echo "s($rad)" | bc -l

echo -n "Cos($deg): "
echo "c($rad)" | bc -l

echo -n "Tan($deg): "
echo "s($rad)/c($rad)" | bc -l

echo "sqrt(25)" | bc -l
echo "2^100" | bc -l

x=14
echo -n "Natural log: ln($x) :"
echo "l($x)" | bc -l

echo -n "Ten base log: log($x) :"
echo "l($x)/l(10)" | bc -l


echo "scale=2;sqrt($x)" | bc -l # sets precision on calculation to 2

echo 1.1 \* 2.2 | bc -l # notice the \ is needed to escape * when no quotes around expr


# Can define a function in bc syntax:
fact="define f (x)
{
    i=x
    fact=1
    while (i > 1)
    {
        fact=fact*i
        i=i-1
    }
    return fact
}"

n=7

factorial=`echo "$fact;f($n)" | bc -l`
echo "$n! = $factorial"







echo - | awk '{print 1.1 + 2.2}'
echo - | awk '{print 1.1 ** 2.2}'
echo - | awk '{print log(10.0)}'
echo - | awk '{print sqrt(2.0)}'
echo - | awk '{print sin(1.0)}'
echo - | awk '{print atan2(1.0, 1.0)}'
myvar=`echo - | awk '{print 1.1 + 2.2}'`
echo $myvar


python -c 'print 1.1 - 2.2'
python -c 'print 2**100'


perl -e 'print 1.1 * 2.2'
echo
perl -e 'print 1.1 / 2.2'

echo

ruby -e 'puts 1.1 + 2.2'
ruby -e 'puts 2**100'










