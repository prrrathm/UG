def num2set(number) :
    numstr = str(number)
    digitset = set()
    
    for i in numstr :
        digitset.add(int(i))

    return digitset

if __name__ == '__main__' :
    n = int(input('number : '))
    print('Digits of number in a set : ',num2set(n), end='\n\n')