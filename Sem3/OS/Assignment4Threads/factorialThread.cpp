#include<stdio.h>
#include<pthread.h>
#include<tgmath.h>

void *factorial(void *p);
int fact(int n);

int main(){
    pthread_t tid1;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&tid1,&attr,factorial,NULL);
    pthread_join(tid1,NULL); 
}

int fact(int n){
    if(n==0 || n==1)
    return 1;
    else 
    return n*fact(n-1);
}
void *factorial(void *p){
    int i,num1;
    printf("Enter Number: ");
    scanf("%d",&num1);
    printf("Factorial is: %d\n",fact(num1));
    pthread_exit(0); 
}