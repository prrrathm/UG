# pattern - 1–x2/2!+x4/4!–x6/6!+...xn/n!
from Q4 import Factorial

def patternsum(x,n) :
    patternsum = 1
    for i in range(2, n+1) :
        patternsum = patternsum + (-1**(i-1)) * i*x / Factorial(i)
    return patternsum

n = int(input())
print(patternsum(12,5))
