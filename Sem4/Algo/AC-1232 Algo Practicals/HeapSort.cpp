//
// Pratham Sharma AC-1232
//

#include <iostream>

using namespace std;

// template class for Heap Sorting Algo
template<class T>
class Heap {
public:
    // creating necessary variables
    int size;
    int heapSize;
    int counter;
    T *array;

    // constructor for initialization
    Heap(int n) {
        size = n;
        heapSize = n;
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

    // creating max heap
    void maxHeapify(T array[], int i) {
        // creating left, right, and largest of heap
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        // making left as largest when its element is greater than the current element
        if (left <= heapSize - 1 && array[left] >= array[i]) {
            largest = left;
            counter++;
        }
        // making right as largest when its element is greater than the largest element
        if (right <= heapSize - 1 && array[right] >= array[largest]) {
            largest = right;
            counter++;
        }
        // when the largest element is changed, swap their position
        if (i != largest) {
            swap(i, largest);
            maxHeapify(array, largest);
        }
    }

    // building the max heap
    void buildMaxHeap() {
        for (int i = size / 2; i >= 0; i--) {
            maxHeapify(array, i);
        }
    }

    // function for swapping elements
    void swap(int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // heap sort function
    void heapSort() {
        // swapping elements and decreasing heap noOfVertices
        for (int i = size - 1; i >= 1; i--) {
            swap(i, 0);
            heapSize = heapSize - 1;
            maxHeapify(array, 0);
        }
    }

    void CallingFunctions() {
        inputArray();
        cout << "---------------------------------------------------------\n";
        cout << "The Array you have entered is ";
        printArray();
        buildMaxHeap();
        cout << "The Heapified Array is ";
        printArray();
        heapSort();
        cout << "The Array After Heap Sort is ";
        printArray();
        cout << "The Total no of comparisons is " << counter << endl;
    }
};

int main() {
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\tTemplate Program to implement Heap Sort Algorithm\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "1. For Integer\n2. For Character\n3. For Float\nSelect your DataType: ";
    int dataType;
    cin >> dataType;

    cout << "---------------------------------------------------------\n";
    cout << "Enter the Size of the Array: ";
    int n;
    cin >> n;

    if (dataType == 1) {
        Heap<int> obj(n);
        obj.CallingFunctions();
    } else if (dataType == 2) {
        Heap<char> obj(n);
        obj.CallingFunctions();
    } else if (dataType == 3) {
        Heap<float> obj(n);
        obj.CallingFunctions();
    } else { cout << "Wrong Data Type\n"; }

    return 0;
}
