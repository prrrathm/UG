def nthfibo(n) :
    a = 1
    b = 1
    elements = [a,b]
    for i in range(2, n) :
        temp = b
        b = a+b
        a = temp
        elements.append(b)
    
    return tuple(elements)

def factorial(num) :
    if num == 1:
        return num
    else :
        return num * factorial(num-1)

if __name__ == '__main__' :
    n = int(input('n : '))
    fseries = nthfibo(n)

    print('Fibonacci series = ', nthfibo(n))
    print('nth element of series = ', fseries[-1])
    print(
        'Factorial of nth element of Fibonacci series = ', 
        factorial(fseries[-1]), 
        end='\n\n'
        )