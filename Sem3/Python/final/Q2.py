def append_string(str1, str2):
    return str1 + " " + str2

def arrangeString(a):
    lower = ''
    upper = ''
    for i in a:
        if i != ' ':
            if i.islower():
                lower = lower+i
            else: 
                upper = upper+i
    return lower+upper

def list_append(List1,List2):
    return List2.extend(List1)

def remove_duplicate(List2):
    List2= [10,20,30,40,50,60,70,5,10,15,20,25,30,35]
    res = []
    for i in List2:
        if i not in res:
            res.append(i)
    return res

def main():
    str1 = "Ronald Brown"
    str2 = "Richard Brown"
    str3 = "Harry/* Potter% is ^a fictional !! character-&"
    
    # APPENDING str1 AND str2
    str4 = append_string(str1,str2) 
    print(str4)
    
    # ARRANGING str4
    print(arrangeString(str4))

    # OCCURENCE OF ROW
    countRow=0
    for x in range(len(str4)):
        if str4[x:x+3] == "row":
            countRow += 1
    print("\nOccurance of row: ", countRow)

    # REMOVE SPECIAL SYMBOLS
    str3_new = ''.join(filter(str.isalnum, str3)) 
    print(str3_new)

    # LIST
    List1= [5,10,15,20,25,30,35]
    List2= [10,20,30,40,50,60,70]

    # APPENDING 40 AFTER 35 in List1
    print('List Before adding 40',List1)
    List1.insert(List1.index(35)+1,'40')            
    print('List After adding 40',List1)
    
    # APPPENDING LIST1 AND LIST2
    print(list_append(List1, List2))
    
    # REMOVE DUPLICATES FROM LIST
    List2 = [10,20,30,40,50,60,70,5,10,15,20,25,30,35,40]
    print(remove_duplicate(List2))
    
main()