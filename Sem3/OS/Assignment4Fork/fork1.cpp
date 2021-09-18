#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

int main() {
    cout << "Following line of code will run 2^3 times \n\n";

    /* fork a child process */
    fork();
    fork();
    fork();

    cout << "Fork" << endl;
    
    return 0;
}