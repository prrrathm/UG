def Fibonacci(n) :
    assert n > 0
    if n == 1 :
        return 0
    elif n == 2 :
        return 1
    else :
        return Fibonacci(n-1)+Fibonacci(n-2)

def Factorial(n) :
    assert n > 0
    if n == 1:
        return n
    else :
        return n * Factorial(n-1)

def FandF(n) :
    return [Fibonacci(n), Factorial(n)]

if __name__ == '__main__' :
    n = int(input('\nn : '))
    output = FandF(n)
    print('nth element of Fibonacci series = ', output[0])
    print('Factorial of',n,' = ', output[1], end='\n\n')