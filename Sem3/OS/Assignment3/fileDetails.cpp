#include<string.h>
#include<iostream>
using namespace std ;

int main(int argc , char* argv[]) {
    char fn[100] = "";

    cout<<"\nFile Name : "<<argv[1];
    cout << "\n\nOwner Access Permission & Date Access Time : \n";
    
    strcat(fn , "ls -l ");
    strcat(fn , argv[1]);
    strcat(fn ,"| awk '{print $1 , $6 , $7 , $8 }'");
    
    system(fn);
    return 0;
}
