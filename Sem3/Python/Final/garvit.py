def bToD(n) :
    num = n
    lst=[]
    dec_value = 0
    base1 = 1
	
    len1 = len(num)
    for i in range(len1 - 1, -1, -1) :
        if (num[i] == '1') :	
            dec_value = dec_value + base1
            lst.append(base1)
            base1 = base1 * 2

    return lst


def b2d2(n) :
    num = n
    dec_num = 0
    m = 1
    # Converting binary into decimal
    for digit in num :
        digit= int(digit)
        dec_num = dec_num + (digit * m)
        m = m * 2
    return dec_num
#num = "10101001";
#print(bToD(num));

def main():
    
    #file-open
    file = open("./myString.txt","r+")
    lst = file.read()
    
    print(b2d2(lst))
    
main()