#include <iostream>
using namespace std;

class node{
    public :
        int data;
        node* next;
        node(int value){
            data = value;            
        }
};

void displayll(node* head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

void insertBefore(node* &head, int value){
    node* n = new node(value);
    if (head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    head = n;
    head->next = temp;
}

void insertAfter(node* &head, int value){
    node* n = new node(value);
    if (head == NULL){
        head = n;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void randomInsert(node* &head, int value){
    node* n = new node(value);
    if (head == NULL){
        head = n;
        return;
    }
    
    int pos = 1;
    node* temp = head;
    while(--pos){
        temp = temp->next;
    }

    node* temp2 = temp;
    temp = n;
    cout << temp->data << endl;
    cout << temp2->data << endl;
    temp2->next = temp;
}

int main(){
    node *a;
    insertAfter(a,2);
    insertAfter(a,1);
    insertBefore(a,0);
    displayll(a);
    cout<< a->data;
    // randomInsert(a,4);
    // displayll(a);
    return 0;
}
