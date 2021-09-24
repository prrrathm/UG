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
            // Node<T> *temp = new Node<T>(this->data);
            // temp->next = this->next;
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
    
    return 0;
}