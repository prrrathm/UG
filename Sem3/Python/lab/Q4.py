def num2set(number) :
    digitset = {number%10}
    number = number % 10
    print(number%10)

    while(number > 10) :
        # digitset.add(number%10)
        number = number % 10
        # print(number)

    # digitset.reverse()
    return digitset

n = int(input('\nnumber : '))
print(num2set(n), end='\n\n')