import os
os.system('clear')

StudentScores = dict({})
StudentScores = {
    'Shaun': {'DS': 50, 'OS': 35, 'CN': 45, 'Python':30, 'GE':50},
    'Ritika': {'DS': 46, 'OS': 31, 'CN': 30, 'Python':30, 'GE':50},
    'Smriti': {'DS': 46, 'OS': 31, 'CN': 30, 'Python':30, 'GE':50},
    'Jacob': {'DS': 50, 'OS': 50, 'CN': 50, 'Python':30, 'GE':50},
}

def TopStudent(stud) :
    lis = [0]
    try:
        for k,v in stud.items() :
            # S = 
            lis.append( sum(v.values()) )
    except : TypeError and ValueError
    pos = lis.index(max(lis)) - 1
    print( max(lis), list(stud)[pos])
    

while(True) :
    print(
        'Select dictionary operation : \n',
        '1. Add new Student\n',
        '2. View Dictionary\n',
        '3. View Top Student\n',
        '4. Exit'
    )
    option = input('->')
        
    if option == '1' : 
        try :
            name = input('Enter Name of Student -> ')
            print('Enter Marks in Subjects')
            DS = float(input('DS -> '))
            OS = float(input('OS -> '))
            CN = float(input('CN -> '))
            Py = float(input('Python ->'))
            GE = float(input('GE -> '))
            
            assert DS < 50 and OS < 50 and CN < 50 and Py < 50 and GE < 50, 'Marks out of Bound'
            
            StudentScores[name] = {
                'DS':DS,
                'OS':OS,
                'CN':CN,
                'Python':Py,
                'GE':GE
            }
        except : ValueError or NameError        
    
    elif option == '2' : 
        print(StudentScores)
        
    elif option == '3' :
        TopStudent(StudentScores)
        
    elif option == '4' :
        exit()
    else :
        continue

# 9. Use dictionary to store marks of the students in 4 subjects.
# Write a function to find the name of the student securing highest percentage.
# (Hint:Namesofstudentsareunique).