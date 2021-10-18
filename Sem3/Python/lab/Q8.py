import os

def listisdigit(List) :
    for i in List :
        if str(i).isdigit() : continue 
        else : 
            return False
        
    return True
def countodds(List) :
    count = 0
    for i in List :
        if int(i)%2 != 0 :
            count = count+1
    
    return count
    
if __name__  == '__main__' :
    os.system('clear')

    A = []
    n = int(input('\nenter size of list : '))
    print('Enter elements of list : ')
    for i in range(n) :
        temp = input('->')
        if temp.isdigit() :
            A.append(int(temp))
        else :
            A.append(temp)
    
           
    # a)
    if listisdigit(A) : print('\nYES list is all digits')
    else : print('\nNO list is not all digits')

    # b)
    if listisdigit(A) :
        print('\nNo of odd values in List : ', countodds(A))
    
    # c)
    else :
        print('\nlargest string in list : ',max(A, key=len))
    
    # d)    
    print('\nlist before reversing = ',A)
    A.reverse()
    print('list after reversing = ',A)

    # e)
    num = input('\nEnter element to search in list : ')
    if num.isdigit() :
        num = int(num)
    if num in A :
        print('\nyes',num,'is present in List.\n')
    else :
        print('\nno',num,'is not present in List.\n')
    



#8.Write a Python program to perform the following using list :
#a) Check if all elements in list are numbers or not.
#b) If it is a numeric list,then count number of odd values in it.
#c) If list contains all Strings, then display largest String in the list.
#d) Display list in reverse form.
#e)Find a specified element in list.
    