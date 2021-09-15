# pattern - 1–x2/2!+x4/4!–x6/6!+...xn/n!

def factorial(num) :
    if num == 1:
        return num
    else :
        return num * factorial(num-1)

def patternsum(x,n) :
    patternsum = 1
    for i in range(2, n+1) :
        patternsum = patternsum + (-1**(i-1)) * i*x / factorial(i)
    return patternsum

n = int(input())
print(patternsum(12,5))
