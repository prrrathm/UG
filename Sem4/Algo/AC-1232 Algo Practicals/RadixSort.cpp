//
// Pratham Sharma AC-1232
//

#include <iostream>

using namespace std;

// template class for Radix Sorting Algo
class Radix {
public:
    // creating necessary variables
    int size;
    int *array;
    int *finalArr;

    // constructor for initialization
    Radix(int n) {
        size = n;
        array = new int[n];
    }

    // array input function
    void inputArray() {
        for (int i = 0; i < size; i++) {
            cout << "Enter Element [" << i << "]: ";
            cin >> array[i];
        }
    }

    // array print function
    void printArray(int *arr) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << ", ";
        }
        cout << "\b\b\n";
    }

    // function to get the maximum element
    int getMax(int *arr) const {
        int tempMax = arr[0];
        for(int i = 0; i < size; i++) {
            if(tempMax < arr[i]) {
                tempMax = arr[i];
            }
        }
        return tempMax;
    }

    // counting sort function
    void countingSort(int arr[], int digit) {
        int maxInd = getMax(arr);
        // array to store the occurrence of each element corresponding to their index
        int *indices = new int[maxInd];
        finalArr = new int[size];

        // initialize all elements equals to zero
        for (int i = 0; i <= maxInd; i++) indices[i] = 0;

        // add the total occurrence of each element corresponding to their indices
        for (int i = 0; i < size; i++) indices[array[i]]++;

        // finding the final position of each element
        for (int i = 1; i <= maxInd; i++) indices[i] += indices[i - 1];

        // storing the sorted array in the final array
        for (int i = size-1; i >=0; i--) {
            finalArr[indices[array[i]]-1] = array[i];
            indices[array[i]]--;
        }
    }

    void RadixSort() {
        int maxInd = getMax(array);
        for(int i = 1; (maxInd/i) > 0; i = i*10) {
            countingSort(array, i);
        }
    }

    void CallingFunctions() {
        inputArray();
        cout << "---------------------------------------------------------\n";
        cout << "The Array you have entered is ";
        printArray(array);
        RadixSort();
        cout << "The Array After Radix Sort is ";
        printArray(finalArr);
    }
};

int main() {
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\tProgram to implement Radix Sort Algorithm\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

    cout << "Enter the Size of the Array: ";
    int n;
    cin >> n;

    Radix obj(n);
    obj.CallingFunctions();

    return 0;
}
