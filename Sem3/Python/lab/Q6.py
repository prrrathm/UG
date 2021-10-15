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
        
if __name__ == '__main__':

    tuplet1 = { 1,2,5,7,9,2,4,6,8,10 }
    tuplet2 = {11,13,15}

    listeven = filterEven(tuplet1)
    print('\nEven numbers Tuple : ',listeven)

    tuple2 = concatTuple(tuplet1,tuplet2)
    print('Concatenated Tuplet : ', tuple2)

    print('maximum value of tuple : ', max(tuplet1))
    print('minimum value of tuple : ', min(tuplet1))