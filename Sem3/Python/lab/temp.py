num = '1 2 3 4 5 a 10'

for i in num :
    if i + num[i+1] in ('123456789') :
        print(i)