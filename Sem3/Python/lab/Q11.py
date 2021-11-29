# Question 10. Write a function that takes a sentence as input from the user and calculates the frequency of each letter. Use a variable of dictionary type to maintain the count

def countletter(txt):
    txtdict = dict({})
    for i in txt :
        if i in txtdict:
            txtdict[i] += 1
        else :
            txtdict[i] = 1
    txtdict.pop(' ')
    return txtdict

txt = input('\nEnter string : ')
print('Frequency of each letter = ',countletter(txt), end='\n\n')
