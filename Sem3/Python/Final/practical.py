import os
import matplotlib.pyplot as plt
os.system("clear")

# countletter function
def countletter(txt):
    txtdict = dict({})
    for i in txt :
        if i in txtdict:
            txtdict[i] += 1
        else :
            txtdict[i] = 1
    return txtdict

# file
fl = "./myStrings.txt"

try :
    # Opening a file and taking data
    file1 = open(fl, 'r')
    
    # assert file should not be empty
    assert os.stat(fl).st_size > 0
    text = file1.read()
    file1.close()
    
    # counting frequency of each letter
    textDict = countletter(text)    
    print('Frequency of each letter = ', textDict, end='\n\n')    
    
    # plotting the histogram
    plt.bar(textDict.keys(),textDict.values(), width=1.0, color='r')    
    plt.show()

except : OSError : print("Can't open/read File")

