#include<iostream>
#define SIZE 5
using namespace std;

template < typename T > class Queue {
    public:
    T * arr;
    int fIndex, rIndex;
    Queue() {
        arr = new T[SIZE];
        fIndex = 0;
        rIndex = 0;
    }
    void display(){
        for (int i=fIndex;i<rIndex;i++)
            cout << arr[i] << "->";
        cout << "...\n";
    }
    bool isFull() {
        return (rIndex + 1) % SIZE == fIndex;
    }
    bool isEmpty() {
        return rIndex == fIndex;
    }
    void enqueue(T item) {
        if (isFull()) {
            cout << "queue is full" << endl;
            return;
        }
        *(this->arr + this->rIndex) = item;
        this->rIndex = (this->rIndex + 1) % SIZE;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return;
        }
        cout<<front()<<" dequeued"<<endl;
        // arr[fIndex] = 0;
        fIndex = (fIndex + 1) % SIZE;
    }
    T front(){
        return *(arr + fIndex);
    }
};

int main() {
    Queue < int > queue;
    int data, operation;
    while(true) {
        cout << "====================================" << endl;
        cout << "Select operation\n";
        cout << "1. Add element to Queue\n";
        cout << "2. Delete element from Queue\n";
        cout << "3. Display Queue\n";
        cout << "4. Front of Queue\n";
        cout << "5. Rear of Queue\n";
        cout << "6. Exit\n";
        cout << "->";
        cin >> operation;
        switch (operation) {
            case 1 :
                cout << "enter item to enqueue:" ;
                cin >> data;
                queue.enqueue(data);
                break;
            case 2 :
                queue.dequeue();
                break;
            case 3 :
                queue.display();
                break;
            case 4 :
                cout << "Front of Queue : " << queue.arr[queue.fIndex] << endl ;
                break;
            case 5 :
                cout << "Rear of Queue : " << queue.arr[queue.rIndex] << endl;
                break;
            case 6 :
                exit(0);
                break;
            default:
                cout << "INVALID INPUT" << endl;
                break;
        }
    }
    return 0;
}