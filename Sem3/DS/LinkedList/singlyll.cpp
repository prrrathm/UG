#include <iostream>
using namespace std;

template <typename T> class Node{
    public :
        T data = 1;
        Node<T> *next;
        Node(T value){
            data = value;
            next = NULL;
        }
        Node(const Node *a){
            this->data = a->data;
            this->next = a->next;
        }
        Node operator=(const Node *a){
            return a;
        }
        void insertNext(T value){
            if(this == NULL){
                this = new Node<T>(value);
                return;
            }
            if (this->next == NULL){
                this->next = new Node<int>(value);
                return;
            }
            this->next->insertNext(value);
        }
        void display(){
            if(this == NULL){
                cout << "NULL\n";
                return;
            }
            cout << this->data << "->";
            this->next->display();
        }
        void insertBefore(T value){
            if(this == NULL){
                this = new Node<T>(value);
                return;
            }
            Node<T> *temp = new Node<int>(this);
            this->data = value;
            this->next = temp;
        }
        void insertAt(int key, T value){
            if(key == 1){
                Node<T> *temp = new Node<int>(this);
                this->data = value;
                this->next = temp;
                return;
            }
            this->next->insertAt(key-1, value);
        }
        bool search(T key){
            if(key == this->data){
                return true;
            }
            if(this->next == NULL){
                return false;
            }
            return this->next->search(key);
        }
        void deleteHead(){
            Node<T> *n = this->next;
            this->data = this->next->data;
            this->next = this->next->next;
            delete n;
        }
        void deleteTail(){
            if(this->next->next == NULL){
                Node<T> *n = this->next->next;
                this->next = NULL;
                delete n;
                return;
            }
            this->next->deleteTail();
        }
        void deleteAt(int key){
            if(key == 1){
                Node<T> *n = this->next;
                this->data = this->next->data;
                this->next = this->next->next;
                delete n;
                return;
            }
            this->next->deleteAt(key-1);
        }
};

int main(){
    
    Node<int> *head;
    int choice, value, pos;
    char flag;

    cout << "List of Operations\n";
    cout << "1. Insert in Beginning\n";
    cout << "2. Insert at Last\n";
    cout << "3. Insert at Random Location\n";
    cout << "4. Delete from Beginning\n";
    cout << "5. Delete from Last\n";
    cout << "6. Delete node after given location\n";
    cout << "7. Search for an element\n";

    while(true){
        cout << "Enter serial number of operation to perform : ";
        cin >> choice;
        switch (choice)
        {
        case 1 : {
            cout << "Enter value : ";
            cin >> value;
            head->insertBefore(value);
            head->display();
            break;
        }
        case 2 : {
            cout << "Enter value : ";
            cin >> value;
            head->insertNext(value);
            head->display();
            break;
        }
        case 3 : {
            cout << "Enter value : ";
            cin >> value;
            head->insertAt(2,value);
            head->display();
            break;
        }
        case 4 : {
            head->deleteHead();
            head->display();
            break;
        }
        case 5 : {
            head->deleteTail();
            head->display();
            break;
        }
        case 6 : {
            cout << "Enter location : ";
            cin >> value;
            value;
            head->deleteAt(value);
            head->display();
            break;
        }
        case 7 : {
            cout << "Enter element to search : ";
            cin >> value;
            // displayll(head);
            if(head->search(value)){
                cout << "yes element is present\n";
            }
            else{
                cout << "no element is not present\n";
            }
            break;
        }
        default:{
            cout << "Invalid Input.\n";
            break;
        }
        }
        cout << "\nDo you want to continue?(y/n) : ";
        cin >> flag;
        if(flag == 'n' || flag == 'N'){
            break;
        }
    }
    return 0;
}