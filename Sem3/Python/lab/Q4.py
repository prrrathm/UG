def num2set(number) :
    numstr = str(number)
    digitset = {int(numstr[0])}
    
    for i in numstr :
        digitset.add(int(i))

    return digitset

n = int(input('number : '))
print('Digits of number in a set : ',num2set(n), end='\n\n')