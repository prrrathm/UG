def revl(lst):
    tmp = list([])
    for i in lst[::-1] :
        tmp.append(i)
    
    return tmp

lst = [1,24,5,78,53,4]
print(revl(lst))