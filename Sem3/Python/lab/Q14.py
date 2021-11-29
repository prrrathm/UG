# Write a function that reads a file and copies only alternative lines to another file. 
# Alternative lines copied should be the odd numbered lines. Use Exception.

import os
os.system("clear")

name1 = input("Enter name of file to copy from =>")
name2 = input("Enter name of file to copy data =>")

try :
	file1 = open(name1, 'r')
	file2 = open(name2, 'w')
	text = file1.readlines()
	type(text)

	for i in range(0, len(text)):
		if(i % 2 != 0):
			file2.write(text[i])
			

	file2.close()
	file2 = open(name2, 'r')
	print("Text Copied in File 2 =>\n\n", file2.read())

	file1.close()
	file2.close()
except : FileNotFoundError