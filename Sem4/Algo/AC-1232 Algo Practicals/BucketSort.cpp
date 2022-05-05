//
// Pratham Sharma AC-1232
//

#include <iostream>
#include <vector>

using namespace std;

// template class for Bucket Sorting Algo
class Bucket {
    // creating necessary variables
    int size;
    float *array;
    vector <float> *bucket;
public:
    // constructor for initialization
    Bucket(int n) {
        this->size = n;
        array = new float[size];
        bucket = new vector<float>[size];
    }

    // array input function
    void inputArray() {
        for (int i = 0; i < size; i++) {
            cout << "Enter Element [" << i << "]: ";
            cin >> array[i];
        }
    }

    // array print function
    void printArray(float *arr) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << ", ";
        }
        cout << "\b\b\n";
    }

    vector<float> insertionSort(vector<float> *arr, int index) {
        // for loop to go through each index (except index[0]) of our array
        for (int j = 1; j < arr[index].size(); j++) {
            // this key will always be inserted into the sorted subarray
            float key = arr[index][j];
            // 'i' will store the index of previous element of key
            int i = j - 1;
            //checking whether the element before key is smaller than it and its index is valid or not
            while (i >= 0 && arr[index][i] > key) {
                // moving the element before key to its next position
                arr[index][i + 1] = arr[index][i];
                // decreasing index i by one so that we can insert key at the correct place in next step
                i = i - 1;
            }
            // inserting key to its correct position
            // if the while loop was executed i.e. key was smaller, 'i' will be decremented by 1 and the key will be
            // inserted at  the correct 'i' position in the next step, else the key's position will not change as i+1=j
            arr[index][i + 1] = key;
        }
        return arr[index];
    }

    void bucketSort() {
        // for loop to create the bucket index and then add corresponding elements to their bucket
        for(int i = 0; i < size; i++) {
            int bucketIndex = int(size * array[i]);
            bucket[bucketIndex].push_back(array[i]);
        }

        // sorting each bucket
        for(int i = 0; i < size; i++) {
            bucket[i] = insertionSort(bucket, i);
        }

        // concatenating all buckets
        int index = 0;
        for(int i = 0; i < size; i++) {
            for(float j : bucket[i]) {
                array[index++] = j;
            }
        }
    }

    void CallingFunctions() {
        inputArray();
        cout << "---------------------------------------------------------\n";
        cout << "The Array you have entered is ";
        printArray(array);
        bucketSort();
        cout << "The Array After Bucket Sort is ";
        printArray(array);
    }
};

int main() {
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\tProgram to implement Bucket Sort Algorithm\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

    cout << "Enter the Size of the Array: ";
    int n;
    cin >> n;

    Bucket obj(n);
    obj.CallingFunctions();

    return 0;
}
