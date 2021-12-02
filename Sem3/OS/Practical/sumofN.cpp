# include <stdio.h>
# include <pthread.h>
# include <iostream>
using namespace std;
void * thread_sum(void *);
int TotalSum=0;
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main() {
    int iNumber,iCount;
    pthread_t tid;
    cout << "Enter Number Up to Which You want to Sum : ";
    cin >> iNumber;
    pthread_create(&tid,NULL,thread_sum,(void *)&iNumber);

    for(iCount=1;iCount<=iNumber;iCount=iCount+2) {
        pthread_mutex_lock(&mVar);
        TotalSum=TotalSum + iCount;
        pthread_mutex_unlock(&mVar);
    }
    
    pthread_join(tid,NULL);
    
    cout << "Final Sum is : " << TotalSum << endl;
    return 0;
}

void *thread_sum(void *no) {
    int *iNumber,iCount;
    iNumber=(int*)no;
    
    for(iCount=2;iCount<=*iNumber;iCount=iCount+2) {
        pthread_mutex_lock(&mVar);
        TotalSum=TotalSum + iCount;
        pthread_mutex_unlock(&mVar);
    }
    pthread_exit(NULL);    
}