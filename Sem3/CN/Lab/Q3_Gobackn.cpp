#include <iostream>
using namespace std;

int main(){
	cout<<"Enter number of bits of frame: ";
	int n;
	cin>>n;
	cout<<"Enter size of window: ";
	int w;
	cin>>w;
	cout<<"Sender Side:- \n";
	for(int j=0; j<n; j++){
		for(int i=1; i<=w && j+i<=n; i++){
			cout<<"Sent frame "<<j+i<<endl;
		}
		j+=w-1;
		cout<<"Recieved Acknowledgement for all? y or n: ";	
		char a;
		cin>>a;
		if(a=='y')
			continue;
		else{
			int count=0;
			int k=j-w+1;
			while(count<3){
				cout<<"Recieved Acknowledgement for "<<k+1<<" ? y or n: ";
				cin>>a;
				if(a=='y')
					k++;
				else{
					j=k-1;
					break;
				}									
			}
		}	
	}
	cout<<"\n**Frame sent successfully**\n";
return 0;	
}
