# Write a program  that makes use of a function to accept a list of n integers and displays a histogram.

import matplotlib.pyplot as plt

n  = int(input('Enter n =>'))
numbers = list([])
yaxis = list([])
for i in range(n) :
    temp = int(input('=>'))
    numbers.append(temp)
    yaxis.append(int(i))

print(yaxis)
plt.plot(numbers,'o')
plt.hist(numbers)
plt.show()

