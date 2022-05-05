//
// Pratham Sharma AC-1232
//

#include <iostream>

using namespace std;

template<class T>
class RandomizedSelect {
public:
    // creating necessary variables
    int size;
    int counter;
    T *array;
    int smallestInd;

    // constructor for initialization
    RandomizedSelect(int n, int i) {
        size = n;
        counter = 0;
        array = new T[n];
        smallestInd = i;
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

    int partition(int start, int end) {
        // using last element as pivot
        T pivEle = array[end];
        // smaller element index
        int i = start-1;

        for (int j = start; j < end; j++) {
            // swapping when the element in less than the pivot element
            counter++;
            if (array[j] <= pivEle) {
                i++;
                swap(array[j], array[i]);
            }
        }
        // swapping pivot element to correct position
        swap(array[i+1], array[end]);

        // return the index of pivot element
        return (i+1);
    }

    int randPartition(int start, int end) {
        int pivRand;
        int n;
        pivRand = start + n%(end - start +1);

        swap(array[end], array[pivRand]);

        return partition(start, end);
    }

    int randomizedSelect(int start, int end, int smallestInd) {
        if (start == end) return array[start];
        int q = randPartition(start, end);
        int k = q - start + 1;
        if (smallestInd == k) return array[q];
        else if (smallestInd < k) return randomizedSelect(start, q - 1, smallestInd);
        else return randomizedSelect(q + 1, end, smallestInd - k);
    }

    void callingFunction() {
        inputArray();
        cout << "---------------------------------------------------------\n";
        cout << "The Array you have entered is ";
        printArray();
        int ithsmallestele = randomizedSelect(0, size-1, smallestInd);
        cout << "ith Smallest Element that you searched in the Array is " << ithsmallestele << endl;
    }
};

int main() {
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\tProgram to implement Randomized Select Algorithm\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

    cout << "---------------------------------------------------------\n";
    cout << "Enter the Size of the Array: ";
    int n;
    cin >> n;
    cout << "Enter the ith smallest element you want to find: ";
    int i;
    cin >> i;

    RandomizedSelect<int> obj(n, i);
    obj.callingFunction();
}