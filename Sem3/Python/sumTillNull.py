def main() :
    S = 0
    while True:
        num = input('number : ')
        if num != '' :
            S += int(num)
            print(str(S))
        else :
            break

main()