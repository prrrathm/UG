//
// Pratham Sharma AC-1232
//

#include <iostream>

using namespace std;

// template class for Merge Sort Algo
template <class T>
class Merge {
public:
    // creating necessary variables
    int size;
    int counter;
    T *array;

    // constructor for initialization
    Merge(int n) {
        size = n;
        counter = 0;
        array = new T[n];
    }

    // array input function
    void inputArray() {
        for (int i = 0; i < size; i++) {
            cout << "Enter Element [" << i << "]: ";
            cin >> array[i];
        }
    }

    // array print function
    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << ", ";
        }
        cout << "\b\b\n";
    }

    // merge function
    void merge(int beg, int mid, int end) {
        // creating noOfVertices of both sub arrays
        int SizeSubArrLeft = mid - beg + 1;
        int SizeSubArrRight = end - mid;

        // creating sub arrays using the noOfVertices
        T subArrLeft[SizeSubArrLeft];
        T subArrRight[SizeSubArrRight];

        // storing values from the array to both sub arrays (i.e. dividing array into two sub arrays)
        for (int i = 0; i < SizeSubArrLeft; i++) {
            subArrLeft[i] = array[beg + i];
        }
        for (int j = 0; j < SizeSubArrRight; j++) {
            subArrRight[j] = array[mid + 1 + j];
        }

        // creating indexes to work on both sub arrays
        int i = 0;
        int j = 0;
        int k = beg;

        // storing elements in array from the sub arrays
        while (i < SizeSubArrLeft && j < SizeSubArrRight) {
            if (subArrLeft[i] <= subArrRight[j]) {
                array[k] = subArrLeft[i];
                i++;
            } else {
                array[k] = subArrRight[j];
                j++;
            }
            k++;
            counter++;
        }

        // storing remaining elements from left sub array to array
        while (i < SizeSubArrLeft) {
            array[k] = subArrLeft[i];
            i++;
            k++;
        }

        // storing remaining elements from right sub array to array
        while (j < SizeSubArrRight) {
            array[k] = subArrRight[j];
            j++;
            k++;
        }
    }

    // function for merge sort
    void mergeSort(int beg, int end) {
        // checking whether the beginning index is smaller than the ending index
        if (beg < end) {
            int mid = (beg + end) / 2;
            mergeSort(beg, mid);
            mergeSort(mid + 1, end);
            merge(beg, mid, end);
        }
    }

    // function to call all functions
    void CallingFunctions() {
        inputArray();
        cout << "---------------------------------------------------------\n";
        cout << "The Array you have entered is ";
        printArray();
        mergeSort(0, size-1);
        cout << "The Array After Merge Sort is ";
        printArray();
        cout << "The Total no of comparisons is " << counter << endl;
    }
};

int main() {
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\tTemplate Program to implement Merge Sort Algorithm\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "1. For Integer\n2. For Character\n3. For Float\nSelect your DataType: ";
    int dataType;
    cin >> dataType;

    cout << "---------------------------------------------------------\n";
    cout << "Enter the Size of the Array: ";
    int n;
    cin >> n;

    if (dataType == 1) {
        Merge<int> obj(n);
        obj.CallingFunctions();
    } else if (dataType == 2) {
        Merge<char> obj(n);
        obj.CallingFunctions();
    } else if (dataType == 3) {
        Merge<float> obj(n);
        obj.CallingFunctions();
    } else { cout << "Wrong Data Type\n"; }

    return 0;
}