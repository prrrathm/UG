def righttriangle(row) :
    for i in range(1, row+1) :
        print(i* '*')

def invertedtriangle(row) :
    space = 0
    for i in range(row, 0, -1) :
        print( (space)*' ' + i*'*' + (i-1)*'*')
        space = space+1

def main() :
    r = int(input('row : '))
    choice = input('Enter right for right and invert for inverted triangle : ')
    righttriangle(r) if choice == 'right' else invertedtriangle(r)

main()