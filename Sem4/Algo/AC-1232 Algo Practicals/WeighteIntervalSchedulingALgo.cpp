//
// Pratham Sharma AC-1232
//

#include <iostream>
#include <algorithm>

using namespace std;

// program to perform weighted interval scheduling algorithm

class IntervalScheduling{
public:
    int start;
    int finish;
    int profit;
};

bool jobCompare(IntervalScheduling ob1,IntervalScheduling ob2){
    return ob2.finish>ob1.finish;
}

int latestNonConflict(IntervalScheduling arr[], int i) {
    for (int j=i-1; j>=0; j--) {
        if (arr[j].finish <= arr[i-1].start)
            return j;
    }
    return -1;
}

int findMaxProfitRec(IntervalScheduling arr[], int n) {
    // Base case
    if (n == 1) return arr[n-1].profit;

    // Find profit when current job is included
    int inclProf = arr[n-1].profit;
    int i = latestNonConflict(arr, n);
    if (i != -1)
        inclProf += findMaxProfitRec(arr, i+1);

    // Find profit when current job is excluded
    int exclProf = findMaxProfitRec(arr, n-1);

    return max(inclProf,  exclProf);
}


int findMaxProfit(IntervalScheduling arr[], int n) {
    sort(arr, arr + n, jobCompare);
    return findMaxProfitRec(arr, n);
}

int main(){
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    IntervalScheduling arr[n];
    for(int i=0;i<n;i++){
        cout << "Enter the start time and finish time and profit of job " << i+1 << ": ";
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
    }
    cout << "Maximum profit is: " << findMaxProfit(arr, n) << endl;
    return 0;
}