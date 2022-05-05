//
// Pratham Sharma AC-1232
//

#include <iostream>

using namespace std;

// template class for Counting Sorting Algo
class Counting {
public:
    // creating necessary variables
    int size;
    int counter;
    int *array;
    int *finalArr;

    // constructor for initialization
    Counting(int n) {
        size = n;
        counter = 0;
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
    int getMax() const {
        int tempMax = array[0];
        for(int i = 0; i < size; i++) {
            if(tempMax < array[i]) {
                tempMax = array[i];
            }
        }
        return tempMax;
    }

    // counting sort function
    void countingSort() {
        int maxInd = getMax();
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

    void CallingFunctions() {
        inputArray();
        cout << "---------------------------------------------------------\n";
        cout << "The Array you have entered is ";
        printArray(array);
        countingSort();
        cout << "The Array After Counting Sort is ";
        printArray(finalArr);
//        cout << "The Total no of comparisons is " << counter << endl;
    }
};

int main() {
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\tProgram to implement Counting Sort Algorithm\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

    cout << "Enter the Size of the Array: ";
    int n;
    cin >> n;

    Counting obj(n);
    obj.CallingFunctions();

    return 0;
}
