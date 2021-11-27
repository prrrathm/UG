#include<unistd.h>		//read(),write(),open(),...
#include<fcntl.h>		//flags O_RDONLY(),...
#include<iostream>		//input output stream
#include<stdio.h>		//error perror....
#include<cstdlib>		//exit..

int main( int argc, char *argv[] )
{
	char buf[128];
	int src, des, n;	//src is source file id, des is destinations and n for checking number of bits read and written
	if (argc != 3)
	{
		std::cerr << "Error! Two files excepted";
		exit(1);
	}
	else
	{
		src = open(argv[1], O_RDONLY);	//open a file in readonly
		if (src == -1)
		{
			perror("Error");
			exit(0);
		}
		else
		{
			des = open(argv[2], O_WRONLY | O_CREAT , 0640);	//set's the flag of opening file as writeonly
			if (des == -1)
			{
				perror("Error");
				close(src);		//close() is used to close a file
				exit(0);
			}
			else
			{
				while ((n = read(src, &buf, 128))> 0)		//reading from src file and storing the characters in buf and their count in n. A max of 128 characters can be read at a time
				{
					if (write( des, &buf, n)!=n)	//if the number of characters sent to be written is not same as number of written characters written in the file then it will throw an error
					{
						perror("Error:");
						close(src);
						close(des);
						exit(0);
					}
				}
				write(STDOUT_FILENO, "Copying Sucessful", 18);//STDOUT_FILENO is the macro storing value for console output
				close(src);
				close(des);
			}
		}
	}
	return 0;
}
