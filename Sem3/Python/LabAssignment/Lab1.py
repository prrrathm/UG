from cgi import print_form


def triangle(row) :
    for i in range(1, row+1) :
        for j in range(1, i+1) :
            print('*', end=' ')
        print('')

def main() :
    r = int(input('row : '))
    triangle(r)

main()