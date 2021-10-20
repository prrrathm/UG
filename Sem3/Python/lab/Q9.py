import os
os.system('clear')

StudentScores = dict({})
StudentScores.get('')

def TopStudent(studDict) :
    for i, v in studDict :
        print(i,v)
    return

while(True) :
    print(
        'Select dictionary operation : \n',
        '1. Add new Student\n',
        '2. View Dictionary\n',
        '3. View Top Student\n',
        '4. Exit'
    )
    option = int(input('->'))
        
    if option == 1 : 
        try :
            name = input('Enter Name of Student -> ')
            print('Enter Marks in Subjects')
            DS = float(input('DS -> '))
            OS = float(input('OS -> '))
            CN = float(input('CN -> '))
            Py = float(input('Python ->'))
            GE = float(input('GE -> '))
                
            StudentScores[name] = {
                'DS':DS,
                'OS':OS,
                'CN':CN,
                'Python':Py,
                'GE':GE
            }
        except : ValueError or NameError        
    
    elif option == 2 : 
        print(StudentScores)
        
    elif option == 3 :
        TopStudent(StudentScores)
        
    elif option == 4 :
        exit()


# 9. Use dictionary to store marks of the students in 4 subjects.
# Write a function to find the name of the student securing highest percentage.
# (Hint:Namesofstudentsareunique).