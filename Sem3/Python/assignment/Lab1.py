# RIGHT TRIANGLE FUNCTION
def righttriangle(row) :
    for i in range(1, row+1) :
        print(i* '*')

#INVERTED TRIANGLE FUNTION
def invertedtriangle(row) :
    space = 0
    for i in range(row, 0, -1) :
        print( (space)*' ' + i*'*' + (i-1)*'*')
        space = space+1

#MAIN FUNCTION
def main() :
    #INPUT NO. OF ROWS AND TYPE OF TRIANGLE
    r = int(input('no. of rows : '))
    choice = input(
        '''Enter 'right' for right and 'inverted' for inverted triangle : '''
        )

    #TERNARY EQUATION
    righttriangle(r) if choice == 'right' else invertedtriangle(r)

main()