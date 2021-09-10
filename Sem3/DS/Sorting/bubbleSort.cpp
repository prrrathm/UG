#include <iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n-1; i++)	
	
	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
}

int main(){
    cout << "Program to Perform Bubble Sort.\n\n";

	int n;
    cout << "size : ";
    cin >> n;
	int *arr = new int[n];

    cout << "Enter elements of array : \n";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    cout << "\nArray before Bubble Sort : ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    bubbleSort(arr, n);

    cout << "\nArray after Bubble Sort : ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}
