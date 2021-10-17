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
  Doublell<int> dll;
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
