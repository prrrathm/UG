# Question 6. Consider a tuplet1 = { 1,2,5,7,9,2,4,6,8,10 }.Write a program to perform following operations :       

#a) Print another tuple whose values are even numbers in the given tuple.
#b) Concatenate a tuplet2 = {11,13,15} with t1.
#c) Return maximum and minimum value from this tuple.

# a)
def filterEven(tuplet):
    listtuplet = list()
    for i in tuplet :
        if i%2 == 0 :
            listtuplet.append(i)

    return tuple(listtuplet)

def concatTuple(t1, t2):
    t1 = list(t1)
    t2 = list(t2)
    
    tuplet = t1 + t2
    return tuple(tuplet)
    

tuplet1 = { 1,2,5,7,9,2,4,6,8,10 }
tuplet2 = {11,13,15}
listeven = filterEven(tuplet1)
print('\n\nEven numbers Tuple : ',listeven)

tuple2 = concatTuple(tuplet1,tuplet2)
print('Concatenated Tuplet : ', tuple2)

