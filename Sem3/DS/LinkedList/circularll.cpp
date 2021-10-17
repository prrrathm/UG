#include<iostream>
using namespace std;

template<typename A> class Node{
    public:
        A data;
        Node<A>* next;
        Node(){
            next = NULL;
        }
        Node(A value){
            data = value;
            next = NULL;
        }
};
template<typename A> class circularll{
    public:
    Node<A>* head;
    circularll(){
        head = NULL;
    }
    int size(){
        int count=1;
        Node<A>* temp = head;
        while(temp->next != head){
            count++;
            temp = temp->next;
        }
        return count;
    }
    void display(){
        if(head == NULL){
            cout<<"linked list is empty"<<endl;
            return;
        }
        // cout<<endl<<"----link list items------"<<endl;
        Node<A>* temp = head;
        while(true){
            cout<<temp->data<<"->";
            temp = temp->next;
            if(temp == head) break;
        }
        cout<<"..."<<endl;
    }
    
    void insertNext(A value){
        if(head == NULL){
            head = new Node<A>(value);
            head->next = head;
            return;
        }
        Node<A>* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = new Node<A>(value);
        temp->next->next = head;
    }
    void insertHead(A value){
        if(head == NULL){
            head = new Node<A>(value);
            head->next = head;
            return;
        }
        Node<A>* temp = head;
        Node<A>* end = head;
        while(end->next != head){
            end = end->next;
        }
        head = new Node<A>(value);
        head->next = temp;
        end->next = head;
    }
    void insertAt(int index, A value){
        if(index > size() || index < 0){
            cout<<"index out of bound !"<<endl;
            return;
        }
        if(index == 0){
            insertHead(value);
            return;
        }
        Node<A>* node = new Node<A>[1];
        node->data = value;
        int count = 0;
        Node<A>* temp = head;
        while(count < index){
            if(count == index-1){
                node->next = temp->next != head ? temp->next : head;
                temp->next = node;
                break;
            }
            count++;
            temp = temp->next;
        }
    }
    void deleteHead(){
        if(head == NULL){
            cout<<"linked list is empty !"<<endl;
            return;
        }
        if(size() == 1) {
            head = NULL;
            return;
        }

        Node<A>* temp = head;
        Node<A>* end = head;
        while(end->next != head) {
            end = end->next;
        }
        head = head->next;
        end->next = head;
        delete temp;
    }
    void deleteTail(){
        if(head == NULL){
            cout <<"Empty List";
            return;
        }
        if(size() == 1){
            deleteHead();
            return;
        }
        Node<A>* temp = head;
        while(temp->next->next != head)
            temp = temp->next;
        
        Node<A>* lastNode = temp->next;
        temp->next = head;
        delete lastNode;
    }
    void deleteAt(int index){
        if(head == NULL){
            cout<<"linked list is empty !"<<endl;
            return;
        }
        if(index >= size() || index < 0){
            cout<<"Index out of bound !"<<endl;
            return;
        }
        if(index == 0){
            deleteHead();
            return;
        }
        int count = 0;
        Node<A>* temp = head;
        while(temp->next != head) {
            if(count == index - 1) {
                temp->next = temp->next->next;
                break;
            }
            count++;
            temp = temp->next;
        }
    }
    bool search(A key){
        Node<A>* temp = head;
        while(temp->next != head){
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }
        if(temp->data == key){
            return true;
        }
        return false;
    }

};

int main(){
    circularll<int> cll;
    int choice, value, pos;
    char flag;
    while(true){
        cout << "Select operation\n";
        cout << "1. Insert in Beginning\n";
        cout << "2. Insert at Last\n";
        cout << "3. Insert at Random Location\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from Last\n";
        cout << "6. Delete node after given location\n";
        cout << "7. Search for an element\n";
        cin >> choice;
        switch (choice){
        case 1 : {
            cout << "Enter value : ";
            cin >> value;
            cll.insertHead(value);
            cll.display();
            break;
        }
        case 2 : {
            cout << "Enter value : ";
            cin >> value;
            cll.insertNext(value);
            cll.display();
            break;
        }
        case 3 : {
            cout << "Enter index : ";
            cin >> pos;
            cout << "Enter value : ";
            cin >> value;
            cll.insertAt(pos,value);
            cll.display();
            break;
        }
        case 4 : {
            cll.deleteHead();
            cll.display();
            break;
        }
        case 5 : {
            cll.deleteTail();
            cll.display();
            break;
        }
        case 6 : {
            cout << "Enter location : ";
            cin >> value;
            value;
            cll.deleteAt(value);
            cll.display();
            break;
        }
        case 7 : {
            cout << "Enter element to search : ";
            cin >> value;
            // displayll(head);
            if(cll.search(value)){
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