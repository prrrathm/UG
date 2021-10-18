#include <iostream>
using namespace std;

template <typename A> class Node{
  private :
    A data;
    Node<A>* next;
    Node<A>* prev;
    template <typename B> friend class Doublell;
  public:
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

template<typename A> class Doublell {
  Node<A>* head;
  public:
    Doublell(){
      head = NULL;
    }
    Doublell(A value){
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
      Node<T>* node = new Node<T>[1];
      node->data = item;
      int count = 0;
      Node<T>* temp = head;
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
    void concat(Doublell<A> first, Doublell<A> second){
          Node<A>* alpha = first.head;
          Node<A>* beta = second.head;
          
          while(alpha != NULL){
              append(alpha->data);
              alpha = alpha->next;
          }
          while(beta != NULL){
              insert(beta->data);
              beta = beta->next;
          }
      }

};

int main(){
  Doublell<int> dll;
    Doublell<int> A, B, C;
    int choice, value, pos;
    while(true){
        cout << "\n===================\n";
        cout << "Select an Operation for Doubly Linked List\n";
        cout << "1. Insert in Beginning\n";
        cout << "2. Insert at Last\n";
        cout << "3. Insert at Random Location\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from Last\n";
        cout << "6. Delete at an Index\n";
        cout << "7. Search an element\n";
        cout << "8. Concatenate\n";
        cout << "9. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1 : {
                cout << "Enter value : ";
                cin >> value;
                A.prepend(value);
                A.display();
                break;
            }
            case 2 : {
                cout << "Enter value : ";
                cin >> value;
                A.insert(value);
                A.display();
                break;
            }
            case 3 : {
                cout << "Enter Index : ";
                cin >> pos;
                cout << "Enter value : ";
                cin >> value;
                A.insertAt(2,value);
                A.display();
                break;
            }
            case 4 : {
                A.deleteHead();
                A.display();
                break;
            }
            case 5 : {
                A.deleteTail();
                A.display();
                break;
            }
            case 6 : {
                cout << "Enter location : ";
                cin >> value;
                value;
                A.deleteAt(value);
                A.display();
                break;
            }
            case 7 : {
                cout << "Enter element to search : ";
                cin >> value;
                if(A.search(value)){
                    cout << "yes element is present\n";
                }
                else{
                    cout << "no element is not present\n";
                }
                break;
            }
            case 8 : {
                cout << "size of other linked list : ";
                cin >> pos;
                cout << "Enter elements of linked list\n";
                while(pos--){
                    cin >> value;
                    B.insert(value);
                }
                C.concat(A,B);
                C.display();
                break;
            }
            case 9 :{
                exit(0);
                break;
            } 
            default:{
                cout << "Invalid Input.\n";
                break;
            }
        }
    }
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
