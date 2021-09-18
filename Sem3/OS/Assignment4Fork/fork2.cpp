#include <stdio.h>
#include <unistd.h>
using namespace std;

int main() {
    int n;
    printf("enter no of times you want to fork : ");
    scanf("%d",&n);
    printf("Following line will output 2^n times\n\n");

    for (int i = 0; i < n; i++){
        fork();
    }

    printf("hello\n");
    
    return 0;
}