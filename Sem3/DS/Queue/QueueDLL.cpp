#include <iostream>
using namespace std;

template <typename A> class Node{
  public :
    A data;
    Node<A>* next;
    Node<A>* prev;
    template <typename B> friend class Doublell;
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
  public:
  Node<A>* head;
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
    void deleteHead(){
      if(head == NULL){
        cout << "Empty List" << '\n';
        return;
      }
      Node<A>* temp = head;
      head = head->next;
      delete temp;
    }
};

int main(){
    Doublell<int> A, B, C;
    int choice, value, pos;
    while(true){
        cout << "\n====================================\n";
        cout << "Select operation\n";
        cout << "1. Add element to Queue\n";
        cout << "2. Delete element from Queue\n";
        cout << "3. Display Queue\n";
        cout << "4. Rear of Queue\n";
        cout << "5. Exit\n";
        cout << "->";
        cin >> choice;
        switch (choice) {
            case 1 : 
                cout << "Enter value ->";
                cin >> value;
                A.insert(value);
                A.display();
                break;
            case 2 : 
                A.deleteHead();
                A.display();
                break;
            case 3 :
                A.display();
                break;
            case 4 :
                cout << "Rear = " << A.head->data;
                break;
            case 5 :
                exit(0);
                break;
            default:
                cout << "Invalid Input.\n";
                break;
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
