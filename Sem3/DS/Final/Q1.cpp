#include<iostream>
using namespace std;

template<typename T>class Node{
    private:
        T data;
        Node<T>* next;
        template<typename U>friend class LinkedList;
    public:
        Node(){
            this->next = NULL;
        }
};

template<typename T>class LinkedList{
    private:
        Node<T>* head;
    public:
        LinkedList(){
            this->head = NULL;
        }

        void add(T item){
            Node<T>* node = new Node<T>[1];
            node->data = item;
            if(head == NULL){
                head = node;
                cout<<"new node added(firstnode) !"<<endl;
                return;
            }
            Node<T>* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = node;
            cout<<"new node added at back!"<<endl;
        }

        int length(){
            int len = 0;
            Node<int>* temp = head;
            while(temp != NULL){
                len++;
                temp = temp->next;
            }
            return len;
        }

        void displayAll(){
            if(head == NULL){
                cout<<"linked list is empty"<<endl;
                return;
            }
            cout<<endl<<"----link list items------"<<endl;
            Node<T>* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" | ";
                temp = temp->next;
            }
            cout<<endl<<"--------------------------"<<endl;
        }

        void remove(int index){
            if(head == NULL){
                cout<<"linked list is empty !"<<endl;
                return;
            }
            if(index >= length() || index < 0){
                cout<<"index out of bound !"<<endl;
                return;
            }
            if(index == 0){
                removeFront();
                cout<<"item removed at index "<<index<<endl;
                return;
            }

            int count = 0;
            Node<T>* temp = head;
            while(temp != NULL){
                if(count == index - 1){
                    temp->next = temp->next->next;
                    cout<<"item removed at index "<<index<<endl;
                    break;
                }
                count++;
                temp = temp->next;
            }
        }

        bool search(T value){
            Node<T>* temp = head;
            while(temp != NULL){
                if(temp->data == value){
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
        
        int indexOf(T value){
            Node<T>* temp = head;
            int n = length();
            for(int i=0; i<n; i++){
                if(temp->data == value){
                    return i;
                }
                temp = temp->next;
            }
            return -1;
        }
};

int main(){
    LinkedList<string> list;
    int ch, index;
    string item;
    while(true){
        cout<<"select option :"<<endl;
        cout<<"1: Reserve a Ticket"<<endl;
        cout<<"2: Cancel a Reservation"<<endl;
        cout<<"3: Check if a ticket is reserved"<<endl;
        cout<<"4: Display Passenger List"<<endl;
        cout<<"5: Exit"<<endl;
        cin>>ch;
        cout<<endl;
        switch (ch) {
        case 1:
            cout<<"Enter Passenger Name to Add =>";
            cin>>item;
            list.add(item);
            break;
        case 2:
            cout<<"Enter Passenger Name to Delete =>";
            cin>>item;
            index = list.indexOf(item);
            if (index != -1)
                list.remove(index);
            break;
        case 3:
            cout<<"Enter Passenger Name to Search =>";
            cin>>item;
            if (list.search(item)){
                cout << "Passenger is in the list";
            break; 
            }
            cout << "Passenger not in the list";
            break;
        case 4:
            list.displayAll();
            break;
        case 5:
            exit(0);
        default:
            cout<<"invalid selection"<<endl;
            break;
        }
    }
    return 0;
}