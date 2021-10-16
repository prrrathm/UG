#include<iostream> 
using namespace std;

void FCFS(int n, int *bt, int *wt, int *tat){
    int i, j;
    wt[0] = 0; //waiting time for first process is 0
    
    //calculating waiting time
    for(i=1; i<n; i++) {
        wt[i] = 0;
        for(j=0; j<i; j++)
            wt[i] += bt[j];
    }

    //calculating turnaround time
    for(i=0; i<n; i++) {
        tat[i] = bt[i] + wt[i];
    }
    //output
    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
    for(i=0; i<n; i++) {
        cout << "\nP[" << i+1 << "]" << "\t\t" << bt[i] 
            << "\t\t" << wt[i] << "\t\t" << tat[i];
    }

}

int averageWT(int n, int *bt, int *wt, int *tat){
    int i, avwt = 0;
    // calculating average waiting time
    for(i=0; i<n; i++) {
        tat[i] = bt[i] + wt[i];
        avwt+=wt[i];
    }
    avwt/=i;
    return avwt;
}
int averageTAT(int n, int *bt, int *wt, int *tat){
    int i, avtat = 0;
    // calculating average turnaround time
    for(i=0; i<n; i++) {
        tat[i] = bt[i] + wt[i];
        avtat+=tat[i];
    }
    avtat/=i;
    return avtat;
}

int main() {
    int n, *bt, *wt, *tat, avwt=0, avtat=0, i, j;
    cout << "Enter total number of processes(maximum 20) : ";
    cin >> n;
    cout << "\nEnter Process Burst Time\n";
    
    //input and initializing
    bt = new int[n];
    wt = new int[n];
    tat = new int[n];
    for(i=0;i<n;i++) {
        cout << "P[" << i+1 << "]:";
        cin >> bt[i];
    }

    FCFS(n,bt, wt, tat);
    avwt = averageWT(n,bt, wt, tat);
    avtat = averageTAT(n,bt, wt, tat);

    cout << "\n\nAverage Waiting Time:" << avwt;
    cout << "\nAverage Turnaround Time:" << avtat << endl;
    return 0;
}