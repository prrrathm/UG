/*COMPUTER NETWORKS PRACTICAL 
NAME: PRATHAM SHARMA
ROLL NO. AC-1232
EXAMINATION ROLL NO.: 20001570038
SEMESTER: 3	YEAR:2
COURSE: B.Sc. (H) COMPUTER SCIENCE*/

#include <iostream>
using namespace std;

void div(int m, int g, int gen[], int amsg[]);

int main(){

	int m,g, *msg, *gen, *amsg;
	cout<<"\nEnter the size of generator:";
		cin>>g;
		gen=new int[g];
			
	cout<<"Enter the size of message:";
		cin>>m;
		msg=new int[m+g-1];
		
	cout<<"\nEnter the message:";
		for(int i=0; i<m; i++)
			cin>>msg[i];

	cout<<"\nEnter the generator:";
		for(int j=0; j<g; j++)
			cin>>gen[j];
				
	cout<<"\nSender Side:-\nMessage:";
		for(int i=0; i<m; i++)
			cout<<msg[i]<<" ";

	cout<<"\nGenerator:";
		for(int j=0; j<g; j++)
		cout<<gen[j]<<" ";
			
		g--;
			
		amsg=new int[m+g];
			
		for(int i=0; i<g; i++){
			msg[m+i]=0;
		}
			
		for(int j=0; j<m+g; j++){
			amsg[j]=msg[j];
		}
			
		div(m, g, gen, amsg);
			
		cout<<"\nCRC:";
			for(int k=0; k<g; k++){
				cout<<amsg[m+k]<<" ";
				msg[m+k]=amsg[m+k];
			}
			
		cout<<"\nTransmitted message:";
			for(int l=0; l<m+g; l++)
				cout<<msg[l]<<" ";	
		cout<<"\n\nReciever Side:-\nEnter the message recieved:";
		for(int a=0; a<m+g; a++)
			cin>>amsg[a];
		div(m+g,g,gen,amsg);
		int b;
		for(b=0; b<=g;b++){
			if(amsg[m+b]==1){
				cout<<"\nThere is an error in the message.\n";
				break;
			}		
		}
		if (b>g)
			cout<<"\nThere is no error in the message.\n";	
			
return 0;	
}

void div(int m1, int g1, int gen[], int amsg[]) {
	for(int i=0; i<m1; i++){
		if (gen[0]== amsg[i]){
			for(int j=0, k=i; j<g1+1; j++, k++){
				if(amsg[k]^gen[j])
					amsg[k]=1;
				else
					amsg[k]=0;
			}
		}
	}
}
