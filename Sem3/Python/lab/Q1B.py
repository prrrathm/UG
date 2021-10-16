from math import sqrt

def areaperimeter(a,b,c) : 
    assert a+b>c and b+c>a and a+c>b
    perimeter = a + b + c
    s = perimeter/2
    area = sqrt(s * (s - a) * (s - b) * (s - c))

    return tuple((area, perimeter))

side1 = float(input('side 1 : '))
side2 = float(input('side 2 : '))
side3 = float(input('side 3 : '))

measurements = areaperimeter(side1, side2, side3)

print('Area = ', measurements[0], '\nPerimeter = ', measurements[1])