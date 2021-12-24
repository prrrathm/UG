try:
    a=open("file1.txt","r")
except FileNotFoundError:
    print("File Does Not Exist")


b=open("file2.txt","w+")
r=a.read()
word=""
vowel=0
char=0
for i in range(len(r)):
    if r[i] in 'aeiouAEIOU':
        vowel+=1
    if r[i]==" " or r[i]=="\n" or i==len(r)-1:  
        if i==len(r)-1:
            char+=1
            word+=r[i]
        b.write(word+"?"+str(char)+"?"+str(vowel)+"\n")
        vowel=char=0
        word=""
    else:
        char+=1
        word+=r[i]
a.close()
b.close()

b=open("file2.txt","r")
r=b.read()
print(r)
