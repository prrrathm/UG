def replacevowel(txt) :
    txtlst = list(txt)
    
    for i in range(len(txtlst)) :
        if txtlst[i] in 'aeiouAEIOU' :
            txtlst[i] = '#'
    return ''.join(txtlst)

def countwords(txt) :
    txtlst = list(txt)
    print(txtlst)

countwords('hello man hor sd')

def main() :

    print (
        '\nProgram to perform the following opeartions : \n',
        '1. Find the length of string.\n',
        '2. Return maximum of three strings.\n',
        '3. Accept a string and replace all vowels with “#”\n',
        '4. Find number of words in the given string.\n',
        '5. Check whether the string is a palindrome or not.\n'
        )

    while True :
        choice = int(input('Enter serial number of desired operation : '))
        
        if choice == 1 :
            txt = input('Enter String : ')
            print('Length of string is = ', len(txt))

        elif choice == 3 :
            txt = input('Enter String : ')
            txt = replacevowel(txt)
            print(txt)

        elif choice == 4 :
            txt = input('Enter sentence : ')
            countwords(txt)

        flag = input('''\nDo you want to continue?(y/n) : ''')
        if flag == 'n' or flag == 'N' :
            break

main()