#include <iostream>
#include <random>
#include <time.h>
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
    srand(time(0));
    int size= 0;
    node* temp1 = head;
    while(temp1 != NULL){
        size++;
        temp1 = temp1->next;
    }
    
    int i = (rand() % size);
    
    temp1 = head;
    while(i--){
        temp1 = temp1->next;
    }
    
    node* temp2 = temp1->next;
    temp1->next = new node(value);
    temp1->next->next = temp2;

}

void deleteBegin(node* &head){
    if(head == NULL){
        cout << "List Empty" << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd(node* &head){
    if (head == NULL){
        cout << "List Empty" ;
        return;
    }

    node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    
    temp->next = NULL;
}

void deletell(node* &head, int key){
    if(head == NULL)
        return;
    
    node* temp = head;
    while(key--){
        temp = temp->next;
        cout << key << endl;
    }
        
}

bool searchll(node* head, int key){
    while(head != NULL){
        if(key == head->data){
            return true;
        }
        head = head->next;
    }
    return false;
}

int main(){
    node* head;
    insertAfter(head, 1);
    insertAfter(head, 3);
    insertAfter(head, 4);
    insertAfter(head, 6);
    insertBefore(head, 0);
    insertRandom(head, 5);
    displayll(head);

    deleteBegin(head);
    deleteEnd(head);
    deletell(head,4);
    displayll(head);

    cout << searchll(head, 5);
    return 0;
}