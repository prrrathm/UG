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
      if(index>size() || index<0){
        return;
      }
      if(head == NULL){
        head = new Node<A>(value);
        return;
      }

      Node<A>* temp = head;
      for(int i=1; i<index-1; i++){
        temp = temp->next;
      }
      Node<A>* tempeNext = temp->next;
      Node<A>* n = new Node<A>(value);
      temp->next = n;
      n->next = tempeNext;
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
    int choice, value;
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
            cout << "Enter value : ";
            cin >> value;
            dll.insertAt(2,value);
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
    dll.insert(2);
    dll.insert(3);
    dll.prepend(1);
    dll.prepend(0);
    dll.insertAt(3,4);
    dll.display();
    dll.deleteAt(3);
    dll.display();
    cout << dll.search(20) << endl;
    return 0;
}

/*
1. prepend _/
2. append _/
3. insertat _/
4. deletehead
5. deletetail
6. deleteat
7. search
 */
