#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main(){
    int n;
    
    cout << "Enter no of elements : ";
    cin >> n;
    int *A = new int[n];

    cout << "Enter elements of array : \n";
    for(int i=0; i<n; i++)
        cin >> A[i];
    
	cout  << "Array before insertion sort : ";
    for(int i=0; i<n; i++)
        cout << A[i] << " ";
		
    insertionSort(A, n);

	cout  << "\nArray After insertion sort : ";
    for(int i=0; i<n; i++)
        cout << A[i]  << " ";

	cout << endl;    
    return 0;
}