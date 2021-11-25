# 13.Write a program that makes use of a function to display 
# sine, 
# cosine, 
# polynomial and 
# exponential curves.
import matplotlib.pyplot as plt
import numpy as np
import math
import os

# Sine and Cosine
os.system("clear")
while(True) :
    print("Select your Graph\n",
        "1. Sine Function\n",
        "2. Cosine Function\n",
        "3. Polynomial Function\n",
        "4. Exponential Function\n",
        "5. Exit")

    choice = int(input("=>"))

    if choice == 1 :
        x = list()
        y = list()
        for i in range(0,200) :
            i = i/10
            x.append(i)
            y.append(math.sin(i))
        plt.plot(x,y)
        plt.xlabel('x -> from 0 to 4pi')
        plt.ylabel('sin(x)')
        plt.title('Plot of sin from 0 to 4pi')
        plt.legend(['sin(x)'])
        plt.show()

    elif choice == 2 :
        x = list()
        y = list()
        for i in range(0,200) :
            i = i/10
            x.append(i)
            y.append(math.cos(i))
        plt.plot(x,y)
        plt.xlabel('x -> from 0 to 4pi')
        plt.ylabel('cos(x)')
        plt.title('Plot of cos from 0 to 4pi')
        plt.legend(['cos(x)'])
        plt.show()
    
    elif choice == 3 :
        # x2-4x+4
        degree = int(input("Enter Degree of polynomial =>"))
        coefficient = list()
        exponent = list()
        polynomial = list()
        print("Now enter pairs of coeffient and exponent of each term.")
        
        #exponent
        exponent = range[1,degree+1]
                
        for i in range(degree) :
            temp1 = int(input("Coefficient of term "+str(i+1)+" =>"))
            coefficient.append(temp1)
            
        for i in range(-20,20) :
            for x in range(degree) :
                temp = coefficient[x] * x ** exponent[x]
        
        print(polynomial)
                
    elif choice == 4 :
        e = int(input("Enter exponent =>"))
        x = list()
        y = list()
        for i in range(0,50) :
            x.append(i)
            y.append(i**e)
        plt.plot(x,y)
        plt.xlabel('x -> 50')
        plt.ylabel('x^'+str(e))
        plt.title('Plot of exponent '+str(e))
        plt.legend(['x^'+str(e)])
        plt.show()
        
    elif choice == 5 :
        exit()