# Write a program  that makes use of a function to accept a list of n integers and displays a histogram.

import matplotlib.pyplot as plt
n  = int(input('Enter n =>'))
numbers = list([])

for i in range(n) :
    temp = int(input('=>'))
    numbers.append(temp)

plt.hist(numbers)
plt.xlabel('n')
plt.title('Histogram of list of Integers')
plt.show()

