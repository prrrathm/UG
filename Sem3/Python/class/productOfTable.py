def prodTable(num, multiples):
  for i in range(1, multiples+1):
    print(str(num) + 'X' + str(i) + ' = ' + str(num*i))

def main():
    n = int(input("number : "))
    m = int(input("no. of multiples : "))
    prodTable(n,m)

main()
