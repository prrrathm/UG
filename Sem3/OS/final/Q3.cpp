#include<iostream>
#include<stdio.h>
#include<unistd.h>
using namespace std;

int main() {
    int a = 7;
    int pid1 = fork();
    if (pid1==0) {
        a++;
        cout<< "1 - value of a is" <<a<<endl; // (1)
    }
    else {
        int pid2= fork();
        if (pid2==0) {
            a--;
            cout<<"2- value of a is"<<a<<endl; // (2)
            exit(0);
        }
    }
    cout<< "3- value of a is" <<a<<endl; // (3)
    return 0;
}