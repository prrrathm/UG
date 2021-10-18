
def listisdigit(List) :
    for i in List :
        if str(i).isdigit() : continue 
        else : 
            return False
        
    return True

def countodds(List) :
    count = 0
    for i in List :
        if i%2 != 0 :
            count = count+1
    
    return count


if __name__  == '__main__' :
    A = [1,2,3,4,6,7]

    # a)
    if listisdigit(A) : print('YES list is all digits')
    else : print('NO')

    # b)
    if listisdigit(A) :
        print('No of odd values in List : ', countodds(A))
        
        


#8.Write a Python program to perform the following using list :
#a) Check if all elements in list are numbers or not.
#b) If it is a numeric list,then count number of odd values in it.
#c) If list contains all Strings, then display largest String in the list.
#d) Display list in reverse form.
#e)Find a specified element in list.
    