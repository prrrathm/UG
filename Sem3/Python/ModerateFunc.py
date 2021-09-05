def moderate(marks) :
    if marks < 40 and marks >= 35 :
        marks = 40
        return marks

marks = int(input('Enter your marks : '))
marks = moderate(marks)
print('Marks after moderation = '+ str(marks))
