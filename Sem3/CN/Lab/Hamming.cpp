#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int *data=new int[4];
	int *msg=new int[7];
	cout<<"Enter 4 bits of data:-\n";
	for(int i=0; i<4; i++)
		cin>>data[i];
	msg[0]=data[0]^data[1]^data[3];
	msg[1]=data[0]^data[2]^data[3];
	msg[2]=data[0];
	msg[3]=data[1]^data[2]^data[3];
	msg[4]=data[1];
	msg[5]=data[2];
	msg[6]=data[3];
	
	cout<<"\nSent message is: ";
	for(int j=0; j<7; j++)
		cout<<msg[j];
	cout<<"\nEnter recieved msg: ";
	data=new int[7];
	int error, a, b, c;
	for(int i=0; i<7; i++)
		cin>>data[i];
	a=data[0]^data[2]^data[4]^data[6];
	b=data[1]^data[2]^data[5]^data[6];
	c=data[3]^data[4]^data[5]^data[6];
	/*for(int j=0; j<7; j++)
		cout<<data[j];*/
	error=c*pow(2,2)+ b*pow(2,1)+ a*pow(2,0);
	cout<<"\nThe error bit is "<<error<<endl<<"The correct message is: ";
	for(int j=0; j<7; j++){	
		if(j==error-1)
			cout<<!data[j];
		else
			cout<<data[j];
	}	
return 0;	
}
