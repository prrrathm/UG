#include<iostream>
//#include<conio.h>
using namespace std;

int main(){
//clrscr();

	int a[4],i=0;
	cout<<" Enter IP Address";
	
	for(i=0;i<4;i++)
		cin>>a[i];
	cout<<"\n IP ADDRESS : " << a[0]<<"."<<a[1]<<"."<<a[2]<<"."<<a[3]<<"\n";
	cout<< " The IP address is in Class:";
	if(a[0]>=0 && a[0]<=127)
		cout<<" Class A";
	else if(a[0]>127 && a[0]<=191)
		cout<<" Class B";
	else if(a[0]>191 && a[0]<=223)
		cout<<" Class C";
	else if(a[0]>223 && a[0]<=239)
		cout<< " Class D";
	else if(a[0]>239 && a[0]<=255)
		cout<<"Class E";
return(0);
}
