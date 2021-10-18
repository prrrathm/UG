import os

def listisdigit(List) :
    flag = True
    for i in List :
        try:
            if float(i) :
                flag = True
        except ValueError:
            flag = False
        
    return flag

def countodds(List) :
    try :
        count = 0
        for i in List :
            if '.' in i :
                a = float(i) * 10 ** (len(i) - i.index('.') - 1)
            else :
                a = int(i)
            if a%2 != 0 :
                count = count+1
        return count
    except ValueError:
        return False
    
def inputList(List, n):
    print('Enter elements of list : ')
    for i in range(n) :
        temp = input('->')
        List.append(temp)
    
if __name__  == '__main__' :
    os.system('clear')

    A = []
    n = int(input('\nenter size of list : '))
    inputList(A,n)
    
    while(True) :
        print(
            '\n-------------------',
            '\nList - ', A,
            '\nSelect operation\n',
            '1. Check if all elements in list are numbers or not\n',
            '2. Count number of odd values in it (if it is numeric)\n',
            '3. Display largest String in the list (it is is string)\n',
            '4. Display list in reverse form\n',
            '5. Find a specified element in list\n',
            '6. Remove the specified element from the list\n',
            '7. Sort the list in descending order\n',
            '8. Find the common members in 2 lists\n',
            '9. Exit',
        )
        choice = int(input('->'))
        if choice == 1 : # a)
            if listisdigit(A) : print('YES list is all digits')
            else : print('NO list is not all digits')
        elif choice == 2 : # b)
            if listisdigit(A) :
                print('No of odd values in List : ', countodds(A))
            else :
                print('List is not Numerical')
        elif choice == 3 : # c)
            if not listisdigit(A) :
                print('largest string in list : ',max(A, key=len))
        elif choice == 4 : # d)    
            print('\nlist before reversing = ',A)
            A.reverse()
            print('list after reversing = ',A)
        elif choice == 5 : # e)
            num = input('Enter element to search in list : ')
            if num in A :
                print('yes',num,'is present in List.\n')
            else :
                print('no',num,'is not present in List.\n')
        elif choice == 6 : # f)
            num = input('Enter element to remove : ')
            if num in A :
                i = A.index(num)
                A.pop(i)
            else :
                print('element not in list!')
        elif choice == 7 : # g)
                A.sort(reverse=True)
        elif choice == 8 :
            B = []
            n = int(input('\nenter size of second list : '))
            inputList(B,n)
            common = list(set(A).intersection(B))
            print('Common members in both list : ',common)
            
        elif choice == 9 :
            exit()
            
            


#8.Write a Python program to perform the following using list :
#a) Check if all elements in list are numbers or not.
#b) If it is a numeric list,then count number of odd values in it.
#c) If list contains all Strings, then display largest String in the list.
#d) Display list in reverse form.
#e) Find a specified element in list.
#f) Remove the specified element from the list. 
#g) Sort the list in descending order.
#h) accept 2 lists and find the common members in them.