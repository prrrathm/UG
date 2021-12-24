def check_Eligibility(n):
    if n < 2:
        return False

    for divisor in range(2, int(n ** 0.5) + 1):
        if n % divisor == 0:
            print("Sorry")
            return False
    
    print("Proceed to Printing")
    return True

def displayPattern(n) :
    if(check_Eligibility(n)):
        idx=ord('A')
        for i in range (0,n):
            cs=chr(idx+i)
            print(
                ' '*(n-i-1),
                cs+
                '*'*(2*i-1),
                end=''
            )
            if(i!=0):
                print(cs)
            else:
                print()
    else:
        print("Pattern Not Possible")


displayPattern(5)