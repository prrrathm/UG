// 1. Write the program CRC-12 algorithm for Noiseless channel.

#include <iostream>
using namespace std;

void div(int m, int g, int gen[], int amsg[]);

int main() {

    // g = size of generator 
    // m = size of message
    // msg = transmitted message
    // gen = generator
    // amsg = recieved message

	int m,g, *msg, *gen, *amsg;
	cout << "\nEnter the size of generator =>";
	cin >> g;
	gen = new int[g];
			
	cout << "Enter the size of message:";
	cin >> m;
	msg = new int[m+g-1];
		
	cout << "\nEnter the message \n";
	for(int i=0; i<m; i++) {
        cout << "=> ";
		cin >> msg[i];
        }

	cout << "\nEnter the generator \n";
	for(int j=0; j<g; j++) {
        cout << "=> ";
		cin >> gen[j];
        }
				
	cout << "\nSender Side:-\nMessage:";
	for(int i=0; i<m; i++) {
		cout << msg[i] << " ";
        }

	cout << "\nGenerator:";
	for(int j=0; j<g; j++){
        cout << gen[j] << " ";
        }
			
	g--;	
	amsg = new int[m+g];
			
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
	for(int l=0; l<m+g; l++) {
		cout<<msg[l]<<" ";
    }
	
    // cout<<"\n\nReciever Side:-\nEnter the message recieved:";
	// for(int a=0; a<m+g; a++) {
	// 	cin>>amsg[a];
    //     }
	div(m+g,g,gen,msg);
	int b;

	for(b=0; b<=g;b++){
		if(amsg[m+b]==1){
			cout<<"\nThere is an error in the message.\n";
			break;
			}		
		}
	if (b>g) {
		cout<<"\nThere is no error in the message.\n";	
        }
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
