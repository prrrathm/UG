#include <iostream>
using namespace std;

int main(){
	cout<<"Enter number of bits:-";
	int n;
	cin>>n;
	
	cout<<"Sender Side:- \n";
	for(int j=0; j<n; j++){
		cout<<"Sent frame "<<j+1<<endl<<"Recieved Acknowledgement? y or n: ";
		char a;
		cin>>a;
		if(a=='y')
			continue;
		else
			j=-1;	
	}
	cout<<"\n**Frame sent successfully**";
return 0;	
}
