// C or C++ program for insertion and
// deletion in Circular Queue
#include<bits/stdc++.h>
using namespace std;

template<typename A> class Queue {
    public :
	A rear, front;
	int size;
	A *arr;
	Queue(int s) {
        front = rear = -1;
        size = s;
        arr = new A[s];
	}
    /* Function to create Circular queue */
    void enQueue(A value) {
        if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))) {
            printf("\nQueue is Full");
            return;
        }
        else if (front == -1) {
            front = rear = 0;
            arr[rear] = value;
        }
        else if (rear == size-1 && front != 0) {
            rear = 0;
            arr[rear] = value;
        }
        else {
            rear++;
            arr[rear] = value;
        }
    }

    // Function to delete element from Circular Queue
    int deQueue() {
        if (front == -1) {
            printf("\nQueue is Empty");
            return INT_MIN;
        }

        int data = arr[front];
        arr[front] = -1;
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (front == size-1)
            front = 0;
        else
            front++;
        return data;
    }

    // Function displaying the elements of Circular Queue
    void displayQueue() {
        if (front == -1) {
            printf("\nQueue is Empty");
            return;
        }
        printf("\nElements in Circular Queue are: ");
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                printf("%d ",arr[i]);
        }
        else {
            for (int i = front; i < size; i++)
                printf("%d ", arr[i]);

            for (int i = 0; i <= rear; i++)
                printf("%d ", arr[i]);
        }
    }

};

/* Driver of the program */
int main() {
    int size, operation, data;
    cout << "Enter size of queue ->";
    cin >> size;
	Queue<int> q(size);
    cout << q.size;
    while(true){
        cout << "\n====================\n";
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
            cout << "Enter Data ->";
            cin >> data;
            q.enQueue(data);
            break;
        case 2 :
            q.deQueue();
            break;
        case 3 :
            q.displayQueue();
            break;
        case 4 :
            cout << "Front of Queue ->" << q.arr[q.front] << endl;
            break;
        case 5 :
            cout << "Rear of Queue ->" << q.arr[q.rear] << endl;
            break;
        case 6 :
            exit(0);
        default:
            cout << "INVALID INPUT" << endl;
            continue;
        }
    }

    printf("\n\n");
	return 0;
}
