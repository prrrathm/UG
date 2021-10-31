# Input a subjects in a tuple as in Example T: 
#   T=(Python_CS1,DS_CS2,OS_CS3,Math_CS4,WDD_CS5)
# Create a dictionary with subject name and code as given below: 
#   Subjects = {‘Python’: ‘CS1’, ‘DS’: ‘CS2’, ‘OS’: ‘CS3’, ‘WDD’: ‘CS5}

print('Enter tuple  : ')
t = input()
a = tuple(x for x in t.split(','))

subjects = dict()

for i in a : 
    pos = int(i.index('_'))
    sub = i[0:pos]
    marks = i[pos+1:-1]
    marks= marks + i[-1]
    subjects[sub] = int(marks)

print(subjects)
