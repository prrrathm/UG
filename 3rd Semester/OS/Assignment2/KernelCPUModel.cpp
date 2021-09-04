#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
    cout << "Kernel version : \n";
    system("cat /proc/sys/kernel/osrelease");
    system("cat /proc/cpuinfo | grep -m 1 'model name'");
    system("cat /proc/cpuinfo | grep -m 1 'model'");    
    return 0;
}