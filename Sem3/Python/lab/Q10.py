# 11.Write a menu-driven program to accept a list of student names and perform the following 
# a.search an element using linear search/binarysearch.
# b.Sort the elements using bubblesort / insertonsort / selectionsort.
import os
import random

def linearsearch(Datalist, key) :
    for i in Datalist :
        if i == key :
            return True
    return False

def binarysearch(Datalist, low, high, key):
    if high >= low:
        mid = (high + low) // 2
        # If element is present at the middle itself
        if Datalist[mid] == key:
            return mid
        # If element is smaller than mid, then it can only
        # be present in left subDatalistay
        elif Datalist[mid] > key:
            return binarysearch(Datalist, low, mid - 1, key)
        # Else the element can only be present in right subDatalistay
        else:
            return binarysearch(Datalist, mid + 1, high, key)
    else:
        # Element is not present in the Datalistay
        return -1

def bubblesort(Datalist) :
    n = len(Datalist)
    for i in range(n-1):
        # Last i elements are already in place
        for j in range(0, n-i-1):
            # traverse the Datalistay from 0 to n-i-1
            # Swap if the element found is greater than the next element
            if Datalist[j] > Datalist[j + 1] :
                Datalist[j], Datalist[j + 1] = Datalist[j + 1], Datalist[j]
                
def insertionsort(Datalist) :
    for i in range(1, len(Datalist)):
        key = Datalist[i]
        # Move elements of Datalist[0..i-1], that are greater than key, to one position ahead
        j = i-1
        while j >=0 and key < Datalist[j] :
                Datalist[j+1] = Datalist[j]
                j -= 1
        Datalist[j+1] = key

def selectionsort(Datalist) :
    for i in range(len(Datalist)):
        # Find the minimum element in remaining 
        # unsorted array
        min_idx = i
        for j in range(i+1, len(Datalist)):
            if Datalist[min_idx] > Datalist[j]:
                min_idx = j
                
        # Swap the found minimum element with 
        # the first element        
        Datalist[i], Datalist[min_idx] = Datalist[min_idx], Datalist[i]

if __name__ == '__main__' :
    os.system('clear')
    students = ['Pratham','Dwitya','Tritya','Chatur']
    while(True) :
        print(
            '\nSelect Operation\n',
            '| 1->View List ',
            '| 2->Insert in List ',
            '| 3->Shuffle List |\n',
            '| 4->Linear Search ',
            '| 5->Binary Search ',
            '| 6-> Bubble Sort |\n',
            '| 7-> Insertion Sort |',
            '| 8-> Selection Sort |', 
            '| 9-> Exit |'
        )
        operation = int(input('Enter->'))
        if (operation == 1) :
            print(students)
        elif (operation == 2) :
            name = input('Enter Name of Student : ')
            students.append(name)    
        elif (operation == 3) :    
            random.shuffle(students)
        elif (operation == 4) :  
            key = input('Enter name to find : ')
            if linearsearch(students, key) : print('Yes',key,'is in list.') 
            else : print('No',key,'is not in list.')
        elif (operation == 5) :
            key = input('Enter name to find : ')
            binarysearch(students,0, len(students)-1, key)  
        elif (operation == 6) :    
            bubblesort(students)
        elif (operation == 7) :    
            insertionsort(students)
        elif (operation == 8) :    
            selectionsort(students)
        elif (operation == 9) :    
            exit()
        else :
            print('INVALID INPUT')