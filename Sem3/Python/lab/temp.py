# x2-4x+4
from math import exp
import matplotlib.pyplot as plt

# degree
degree = int(input("Enter Degree of polynomial =>"))

# exponent
e = reversed(range(degree+1))
exponent = [*e]
print(exponent)

# coefficient
coefficient = list()
print("\nEnter coeffients")        
for i in range(degree+1) :
    temp = int(input("=>"))
    coefficient.append(temp)

# polynomial
polynomial = list()
for i in range(-20,20) :
    for x in range(degree) :
        temp = coefficient[x] * (i ** exponent[x]+1)
    # temp = temp + coefficient[-1]*i
    print(temp)
    polynomial.append(temp)
print(polynomial)


plt.plot([*range(-20,20)], polynomial)
plt.xlabel('x -> 50')
plt.ylabel('x^')
plt.title('Plot of exponent')
plt.legend(['x^'])
plt.show()