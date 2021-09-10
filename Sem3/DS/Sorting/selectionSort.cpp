#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        //swapping
        int temp = arr[min_idx];
	    arr[min_idx] = arr[i];
	    arr[i] = temp;
    }
}

int main() {
    cout << "Program to Perform Bubble Sort.\n\n";

	int n;
    cout << "size : ";
    cin >> n;
	int *arr = new int[n];

    cout << "Enter elements of array : \n";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    cout << "\nArray before Selection Sort : ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    selectionSort(arr, n);

    cout << "\nArray after Selection Sort : ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}
