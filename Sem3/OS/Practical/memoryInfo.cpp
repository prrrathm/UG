#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
    cout<<"Configured Memory -- meminfo : \n";
    system("cat /proc/meminfo | grep 'MemTotal'");
    cout<<"Configured Memory -- vmstat : \n";
    system("vmstat -s | grep 'total memory'");
    cout<<"Free Memory -- meminfo : \n";
    system("cat /proc/meminfo | grep 'MemFree'");
    cout<<"Free Memory -- vmstat : \n";
    system("vmstat -s | grep 'free memory'");
    cout<<"Used Memory -- vmstat : \n";
    system("vmstat -s | grep 'used memory'");
    return 0;
}