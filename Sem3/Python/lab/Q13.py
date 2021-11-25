# 13.Write a program that makes use of a function to display 
# sine, 
# cosine, 
# polynomial and 
# exponential curves.
import matplotlib.pyplot as plt
import numpy as np
import math

# Sine and Cosine
x = list()
y = list()
z = list()

for i in range(0,200) :
    i = i/10
    x.append(i)
    y.append(math.sin(i))
    z.append(math.cos(i))

plt.plot(x,y,x,z)
plt.xlabel('x -> from 0 to 4pi')
plt.ylabel('sin(x) and cos(x)')
plt.title('Plot of sin and cos from 0 to 4pi')
plt.legend(['sin(x)', 'cos(x)'])
plt.show()

