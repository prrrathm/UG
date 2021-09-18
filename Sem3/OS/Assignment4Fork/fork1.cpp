#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

int main() {
    cout << "Fork 0" << endl;
    
    /* fork a child process */
    fork();
    cout << "Fork 1" << endl;
    
    /* fork another child process */
    fork();
    cout << "Fork 2" << endl;
    
    /* and fork another */
    fork();
    cout << "Fork 3" << endl;
    
    return 0;
}