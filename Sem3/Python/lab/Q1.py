from math import sqrt

def areanperimeter(a,b,c) : 
    if (a+b>c and b+c>a and a+c>b) :
        return -1
    else :
        perimeter = a + b + c
        s = perimeter/2
        area = sqrt(s * (s - a) * (s - b) * (s - c))

        measures = (
            'area = ' + str(area) + ' unit sq.', 
            'perimeter = ' + str(perimeter) + ' units'
            )

        return measures

side1 = float(input('side 1 : '))
side2 = float(input('side 2 : '))
side3 = float(input('side 3 : '))

print(areanperimeter(side1, side2, side3))