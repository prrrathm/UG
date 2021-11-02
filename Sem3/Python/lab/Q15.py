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
print(p1.name,p1.marks, Student.maxavg)