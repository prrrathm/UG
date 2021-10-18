#include <iostream>
using namespace std;

template<typename T>class Node{
  public:
        T data;
        Node<T>* next;
        template<typename U>friend class LinkedList;
        Node(){
            this->next = NULL;
        }
        Node(T value){
            this->data = value;
            this->next = NULL;
        }
};
template<typename T>class LinkedList{
    // private:
    public:
        Node<T>* head;
        LinkedList(){
            this->head = NULL;
        }
        void display(){
            Node<T> *temp = head;
            while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
            }
            cout << "NULL\n";
        }
        void prepend(T value){
            Node<T>* temp = head;
            head = new Node<T>(value);
            head->next = temp;
        }
        int length(){
            int len = 0;
            Node<T>* temp = head;
            while(temp != NULL){
                len++;
                temp = temp->next;
            }
            return len;
        }
        T deleteHead(){
            if(head == NULL){
                cout << "Empty List" << '\n';
                return -1;
            }
            Node<T>* temp = head;
            head = head->next;
            T data = temp->data;
            delete temp;
            return data;
        }
        void deleteAll(){
            while(length() != 0){
                deleteHead();
            }
        }
};

int main(){
  LinkedList<int> Stack;
      cout << "Stack implemented as Array";
    int choice;
    while(true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n";
        cout<< "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Display top\n";
        cout << "5. Stack empty?\n"; 
        cout << "6. Clear stack\n";
        cout << "7. Exit" << endl;
        cout << "Enter a choice(1-6): ";
        cin >> choice;

        switch(choice) {
            case 1:
                int element;
                cout << "Enter element to push: ";
                cin >> element;
                // my_stack.push(element);
                Stack.prepend(element);
                cout << "Pushed to stack\n";
                break;
            case 2: {
                int popped_element = Stack.deleteHead();
                cout << "Top most element popped: " << popped_element << endl;
                break;}
            case 3:
                cout << "Stack right now:\n";
                Stack.display();
                break;
            case 4:
                cout << "Top most element: " << Stack.head->data << endl;
                break;
            case 5:
                Stack.length() == 0 ? cout << "Stack is empty right now.\n" : cout << "Stack is not empty right now.\n";
                break;
            case 6:
                Stack.deleteAll();
                cout << "Stack cleared.\n";
                break;
            case 7:
                exit(0);
                break;
            default:
                cout << "Invalid Input!! Please Try Again.\n" << endl; 
                break;
        }
    }
    return 0;
}
