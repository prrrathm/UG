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

void displayll(node* head);
void insertAfter(node* &head, int value);
void insertBefore(node* &head, int value);
void insertRandom(node* &head, int value);
void deleteBegin(node* &head);
void deleteEnd(node* &head);
void deletell(node* &head, int key);
bool searchll(node* head, int key);


int main(){

    node* head;
    insertAfter(head,0);
    int choice, value, pos;
    char flag;

    cout << "List of Operations\n";
    cout << "1. Insert in Beginning\n";
    cout << "2. Insert at Last\n";
    cout << "3. Insert at Random Location\n";
    cout << "4. Delete from Beginning\n";
    cout << "5. Delete from Last\n";
    cout << "6. Delete node after given location\n";
    cout << "7. Search for an element\n";
    cout << "Enter serial number of operation to perform : ";
    cin >> choice;

    while(true){
        switch (choice)
        {
        case 1 : {
            cout << "Enter value : ";
            cin >> value;
            insertBefore(head,value);
            displayll(head);
            break;
        }
        case 2 : {
            cout << "Enter value : ";
            cin >> value;
            insertAfter(head,value);
            displayll(head);
            break;
        }
        case 3 : {
            cout << "Enter value : ";
            cin >> value;
            insertRandom(head,value);
            displayll(head);
            break;
        }
        case 4 : {
            deleteBegin(head);
            displayll(head);
            break;
        }
        case 5 : {
            deleteEnd(head);
            displayll(head);
            break;
        }
        case 6 : {
            cout << "Enter location : ";
            cin >> value;
            value++;
            deletell(head,value);
            displayll(head);
            break;
        }
        case 7 : {
            cout << "Enter element to search : ";
            cin >> value;
            bool sresult = searchll(head,value);
            // displayll(head);
            if(sresult){
                cout << "yes element is presentn\n";
            }
            else{
                cout << "no element is not presentn\n";
            }
            break;
        }
        default:
            break;
        }
        cout << "\nDo you want to continue?(y/n) : ";
        cin >> flag;
        if(flag == 'n' || flag == 'N'){
            break;
        }
    }

    // insertAfter(head, 1);
    // insertAfter(head, 3);
    // insertAfter(head, 4);
    // insertAfter(head, 6);
    // insertBefore(head, 0);
    // insertRandom(head, 5);
    // displayll(head);
    // deleteBegin(head);
    // deleteEnd(head);
    // displayll(head);
    // deletell(head,3);
    // displayll(head);

    return 0;
}

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
    key--;
    while(--key){
        temp = temp->next;
    }
    node* temp2 = temp->next;
    temp->next = temp->next->next;
    cout << temp->data << endl;
    delete temp2;

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

