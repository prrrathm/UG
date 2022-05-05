//
// Pratham Sharma AC-1232
//

#include <iostream>

using namespace std;

// template class for Insertion Sorting Algo
template<class T>
class Insertion {
public:
    // creating necessary variables
    int size;
    int counter;
    T *array;
    T key;

    // constructor for initialization
    Insertion(int n) {
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

    // insertion sort function
    void insertionSort() {
        int i, j;
        // for loop to go through each index (except index[0]) of our array
        for (j = 1; j < size; j++) {
            // this key will always be inserted into the sorted subarray
            key = array[j];
            // increasing the total no of comparisons
            counter++;
            // 'i' will store the index of previous element of key
            i = j - 1;
            //checking whether the element before key is smaller than it and its index is valid or not
            while (i >= 0 && array[i] > key) {
                // moving the element before key to its next position
                array[i + 1] = array[i];
                // increasing the total no of comparisons
                counter++;
                // decreasing index i by one so that we can insert key at the correct place in next step
                i = i - 1;
            }
            // inserting key to its correct position
            // if the while loop was executed i.e. key was smaller, 'i' will be decremented by 1 and the key will be
            // inserted at  the correct 'i' position in the next step, else the key's position will not change as i+1=j
            array[i+1] = key;
        }
    }

    void CallingFunctions() {
        inputArray();
        cout << "---------------------------------------------------------\n";
        cout << "The Array you have entered is ";
        printArray();
        insertionSort();
        cout << "The Array After Insertion Sort is ";
        printArray();
        cout << "The Total no of comparisons is " << counter << endl;
    }
};

int main() {
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\tTemplate Program to implement Insertion Sort Algorithm\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "1. For Integer\n2. For Character\n3. For Float\nSelect your DataType: ";
    int dataType;
    cin >> dataType;

    cout << "---------------------------------------------------------\n";
    cout << "Enter the Size of the Array: ";
    int n;
    cin >> n;

    if (dataType == 1) {
        Insertion<int> obj(n);
        obj.CallingFunctions();
    } else if (dataType == 2) {
        Insertion<char> obj(n);
        obj.CallingFunctions();
    } else if (dataType == 3) {
        Insertion<float> obj(n);
        obj.CallingFunctions();
    } else { cout << "Wrong Data Type\n"; }

    return 0;
}
