// Program implementation in C++ for Round Robin scheduling 
#include<iostream> 
using namespace std; 

//The Function to find the waiting time for all processes 
void fWaitingTime(int n, int bt[], int wt[], int quantum){ 
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 

	int t = 0; // for Current time 
	while (1) { 
		bool done = true; 
		for (int i = 0 ; i < n; i++)  { 
			if (rem_bt[i] > 0) { 
				done = false; // indicates there is a pending process 
				if (rem_bt[i] > quantum) { 
					t += quantum; 
					rem_bt[i] -= quantum; 
				} 
				else { 
					t = t + rem_bt[i]; 
					wt[i] = t - bt[i]; 
					rem_bt[i] = 0; 
				} 
			} 
		} 
		// If all the processes are done 
		if (done == true) 
		break; 
	} 
} 

// Function used to calculate the turn around time 
void fTurnAroundTime(int n, int bt[], int wt[], int tat[]) { 
	// calculating turnaround time by adding bt[i] + wt[i] 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 

// Function to calculate the average time 
void findavgTime(int n, int bt[], int quantum) { 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	fWaitingTime(n, bt, wt, quantum);
	fTurnAroundTime(n, bt, wt, tat);

	cout << "Processes "<< " Burst time " << " Waiting time " << " Turn around time\n"; 
	for (int i=0; i<n; i++) { 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl; 
	}
	
	cout << "Average waiting time = " << (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = " << (float)total_tat / (float)n; 
} 

//Given below is the Driver Code
int main() { 
	// process id's
	int processes[] = {1, 2, 3, 4};
	int size;
	cout << "Enter no of processes : ";
	cin >> size;

	// Burst time of all processes 
	int *burst_time = new int[size];
	cout << "\nEnter Process Burst Time\n";
    for(int i=0;i<size;i++) {
        cout << "P[" << i+1 << "]:";
        cin >> burst_time[i];
    }

	// Time quantum 
	int quantum = 2; 
	findavgTime(size, burst_time, quantum); 
	cout << endl;
	return 0; 
} 
