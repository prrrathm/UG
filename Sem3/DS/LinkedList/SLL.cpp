#include <iostream>
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
      Node(T value){
          this->data = value;
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
      void display(){
        Node<T> *temp = head;
        while(temp != NULL){
          cout << temp->data << "->";
          temp = temp->next;
        }
        cout << "NULL\n";
      }
      void append(T value){
          Node<T> *temp = head;
          if(head == NULL){
            head = new Node<T>(value);
            return;
          }
          while(temp->next != NULL){
            temp = temp->next;
          }
          temp->next = new Node<T>(value);
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
      void insert(int index, T value){
        if (index > length() || index < 0){
          cout << "out of bounds!!" << '\n';
          return;
        }
        Node<T>* temp = head;
        for(int i=0; i < index-1; i++){
          temp = temp->next;
        }
        Node<T>* n = temp->next;
        temp->next =  new Node<T>(value);
        temp->next->next = n;
      }
      void deleteHead(){
        if(head == NULL){
          cout << "Empty List" << '\n';
          return;
        }
        Node<T>* temp = head;
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
        Node<T>* temp = head;
        while(temp->next->next != NULL){
          temp = temp->next;
        }
        Node<T>* n = temp->next;
        temp->next = NULL;
        delete n;
      }
      void deleteAt(int index){
        if (index > length() || index < 0){
          cout << "out of bounds!!" << '\n';
          return;
        }
        if(head == NULL){
          cout << "Empty List" << '\n';
          return;
        }
        Node<T>* temp = head;
        for(int i=0; i<index-2; i++){
          temp = temp->next;
        }
        Node<T>* n = temp->next;
        temp->next = n->next;
        delete n;
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
      void concat(LinkedList<T> first, LinkedList<T> second){
          Node<T>* alpha = first.head;
          Node<T>* beta = second.head;
          
          while(alpha != NULL){
              append(alpha->data);
              alpha = alpha->next;
          }
          while(beta != NULL){
              append(beta->data);
              beta = beta->next;
          }
      }
};

int main(){
  LinkedList<int> A, B, C;
  A.append(1);
  A.append(3);
  A.prepend(2);
  A.insert(1,4);
  A.display();

  B.append(3);
  B.append(6);
  B.prepend(5);
  B.insert(1,5);
  B.display();
  
  C.concat(A,B);
  C.display();
  return 0;
}
