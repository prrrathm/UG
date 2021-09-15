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
    cout << "NULL" << endl;
}

void insertAfter(node* &head, int value){
    node* n = new node(value);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertBefore(node* &head, int value){
    if(head == NULL){
        head = new node(value);
        return;
    }
    node* temp = head;
    head = new node(value);
    head->next = temp;
}

void insertRandom(node* &head, int value){
    if (head == NULL){
        head = new node(value);
        return;
    }
    node* traver = head;
    int i = 3;
    while(i--){
        traver = traver->next;
        cout << i;
    }
    node* n = new node(value);
    node* temp = traver;
    traver = n;
    traver->next = temp;
}

int main(){
    node* head;
    insertAfter(head, 1);
    insertAfter(head, 3);
    insertAfter(head, 4);
    insertAfter(head, 6);
    insertBefore(head, 0);
    insertRandom(head, 50);
    displayll(head);
    return 0;
}