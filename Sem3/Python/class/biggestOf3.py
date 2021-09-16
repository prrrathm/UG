set = []

for i in range(1,4) :
    temp = int(input('Enter element no '+str(i)+' : '))
    set.append(temp)

big = set[0]
if (set[1] > big) :
    big = set[1]
if (set[2] > big) :
    big = set[2]

print('Biggest number out of the three = '+str(big))