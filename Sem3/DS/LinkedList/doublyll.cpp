#include <iostream>
using namespace std;

template <typename A> class Node{
  public:
    A data;
    Node<A>* next;
    Node<A>* prev;
    template <typename B> friend class Doublyll;
    Node(){
      this->prev = NULL;
      this->next = NULL;
    }
    Node(A value){
      this->data = value;
      this->prev = NULL;
      this->next = NULL;
    }
};

template<typename A> class Doublyll {
  Node<A>* head;
  public:
    Doublyll(){
      head = NULL;
    }
    Doublyll(A value){
      head = new Node<A>(value);
    }
    void display(){
      Node<A>* temp = head;
      while(temp != NULL){
        cout << temp->data <<"<->";
        temp= temp->next;
      }
      cout << "NULL" << '\n';
    }
    int size(){
      int count=0;
      Node<A>* temp = head;
      while(temp != NULL){
        count++;
        temp = temp->next;
      }
      return count;
    }
    void insert(A value){
      if (head == NULL){
        head = new Node<A>(value);
        return;
      }
      Node<A>* temp = head;
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next = new Node<A>(value);
      temp->next->prev = temp->next;
    }
    void prepend(A value){
      if(head == NULL){
        head = new Node<A>(value);
        return;
      }
      Node<A>* temp = head;
      head->prev = new Node<A>(value);
      head = head->prev;
      head->next = temp;
    }
    void insertAt(int index, A value){
        if(index > size() || index < 0){
            cout<<"index out of bound !"<<endl;
            return;
        }
        if(index == 0){
            insert(value);
            return;
        }
      Node<A>* node = new Node<A>[1];
      node->data = value;
      int count = 0;
      Node<A>* temp = head;
      while(temp != NULL && count < index){
        if(count == index-1){
          if(temp->next != NULL){
            node->next = temp->next;
          }
          temp->next = node;
          node->prev = temp;
          cout<<"new node added at index "<<index<<" !"<<endl;
          break;
        }
        count++;
        temp = temp->next;
      }
    }
    void deleteHead(){
      if(head == NULL){
        cout << "Empty List" << '\n';
        return;
      }
      Node<A>* temp = head;
      head = head->next;
      delete temp;
    }
    void deleteTail(){
      if(head == NULL){
        cout << "Empty List" << '\n';
        return;
      }
      if(head->next == NULL){
        deleteHead();
        return;
      }
      Node<A>* temp = head;
      while(temp->next->next != NULL){
        temp = temp->next;
      }
      Node<A>* temp2 = temp->next;
      temp->next = NULL;
      delete temp2;
    }
    void deleteAt(int index){
      if(head == NULL){
        cout << "Empty List" << '\n';
        return;
      }
      if(index>size() || index<0){
        cout << "Invalid Index" << '\n';
        return;
      }
      Node<A>* temp = head;
      for(int i=1; i<index-1; i++){
        temp = temp->next;
      }
      Node<A>* temp2 = temp->next;
      temp->next = temp->next->next;
      delete temp2;
    }
    bool search(A key){
      Node<A>* temp = head;
      while (temp != NULL) {
          if(temp->data == key){
            return true;
          }
          temp = temp->next;
      }
      return false;
    }

};

int main(){
    Doublyll<int> dll;
    int choice, value, pos;
    char flag;
    while(true){
        cout << "List of Operations\n";
        cout << "1. Insert in Beginning\n";
        cout << "2. Insert at Last\n";
        cout << "3. Insert at Random Location\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from Last\n";
        cout << "6. Delete node after given location\n";
        cout << "7. Search for an element\n";
        cout << "Choice : ";
        cin >> choice;
        switch (choice){
        case 1 : {
            cout << "Enter value : ";
            cin >> value;
            dll.prepend(value);
            dll.display();
            break;
        }
        case 2 : {
            cout << "Enter value : ";
            cin >> value;
            dll.insert(value);
            dll.display();
            break;
        }
        case 3 : {
            cout << "Enter index : ";
            cin >> pos;
            cout << "Enter value : ";
            cin >> value;
            dll.insertAt(pos,value);
            dll.display();
            break;
        }
        case 4 : {
            dll.deleteHead();
            dll.display();
            break;
        }
        case 5 : {
            dll.deleteTail();
            dll.display();
            break;
        }
        case 6 : {
            cout << "Enter location : ";
            cin >> value;
            value;
            dll.deleteAt(value);
            dll.display();
            break;
        }
        case 7 : {
            cout << "Enter element to search : ";
            cin >> value;
            // displayll(head);
            if(dll.search(value)){
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
