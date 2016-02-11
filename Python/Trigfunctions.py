
from pylab import *

linewidth = '4'

x = arange(0.0, 4.0, 0.01)
y1 = 10*sin(3*x)
plot(x, y1, linewidth)

y2 = 5*cos(5*pi*x)
plot(x, y2, linewidth)

xlabel('Radians')
ylabel('Amplitude')
title('Trigonometric Functions')
grid(True)
savefig("TrigFunctions.png")
show()
