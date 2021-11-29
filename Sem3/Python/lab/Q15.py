# Define a class Student to store his/her name and marks in three subjects.
# Use a class variable to store the maximum average marks of the class.
# Use constructor and destructor to initialize and destroy the objects.
import os
os.system('clear')

class Student :
    maxavg = 0.0
    def __init__(self, name,marks=[]) :
        self.name = name
        self.marks = marks
        if sum(marks)/3 > Student.maxavg :
            Student.maxavg = round(sum(marks)/3,2)

p1 = Student('Pratham',[12,13,14])
p2 = Student('Divyam',[14,23,16])

name3 = input('Enter Name of Student =>')
mark3 = []
for i in range(3) :
    temp = int(input('Enter marks in subject '+str(i+1)+" =>"))
    mark3.append(temp)
    
p3 = Student(name3,mark3)
print(
    "Name","\t Marks\n",
    p1.name,p1.marks, "\n",
    p2.name,p2.marks, "\n",
    p3.name,p3.marks, "\n",
    "\nMaximum Average marks of class = ",Student.maxavg)