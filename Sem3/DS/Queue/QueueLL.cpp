#include<iostream>
#define SIZE 5
using namespace std;

template < typename T > class Queue {
    private:
    T * arr;
    int fIndex, rIndex;
    public:
        Queue() {
            arr = new T[SIZE];
            fIndex = 0;
            rIndex = 0;
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
        fIndex = (fIndex + 1) % SIZE;
    }
    T front(){
        return isEmpty() ? NULL : *(arr + fIndex);
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
            case 1:
                cout << "enter item to enqueue:" << endl;
                cin >> data;
                queue.enqueue(data);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                if (queue.isEmpty()) {
                    cout << "queue is empty" << endl;
                } else {
                    cout << "front: " << queue.front() << endl;
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "invalid selection" << endl;
                break;
        }
    }
    return 0;
}