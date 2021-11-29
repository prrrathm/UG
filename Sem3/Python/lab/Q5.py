# pattern - 1–x2/2!+x4/4!–x6/6!+...xn/n!
from Q3 import Factorial

def patternsum(x,n) :
    assert x > 0 and n > 0
    patternsum = 1
    for i in range(2, n+1) :
        patternsum = patternsum + (-1**(i-1)) * (i*x / Factorial(i))
    return patternsum

n = int(input("Enter n =>"))
x = int(input("Enter x =>"))
print(patternsum(x,n))
