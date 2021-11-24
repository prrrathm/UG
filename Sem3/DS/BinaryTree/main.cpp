// Binary Search Tree with following Operations
// (i) Insert an element x
// (ii) Delete an element x
// (iii) Search for an element x in the BST and change its value to y and then place the node with value y at its appropriate position in the BST
// (iv) Display the elements of the BST in preorder, inorder, and postorder traversal

#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    cout << "\tBINARY TREE\n";
    // Tree<int> tr;
    // tr.add(4);
    // tr.add(6);
    // tr.add(1);
    // tr.add(9);
    // tr.add(2);
    // tr.add(0);
    // tr.add(89);
    // tr.add(12);
    // tr.add(32);
    // tr.add(5);
    // tr.add(22);
    // tr.add(222);
    // tr.print();
    // cout << tr.search(222) << endl;

    Tree<int> A, B, C;
    int choice, value, pos;
    while(true){
        cout << "\n===================\n";
        cout << "Select an Operation \n";
        cout << "1. Insert an Element\n";
        cout << "2. Delete at Element\n";
        cout << "3. Search an element\n";
        cout << "4. Display an Element in Preorder\n";
        cout << "5. Display an Element in Inorder\n";
        cout << "6. Display an Element in Postorder\n";
        cout << "7. Exit\n=>";
        cin >> choice;
        switch (choice) {
            case 1 : {
                cout << "Enter value : ";
                cin >> value;
                A.add(value);
                // A.display();
                break;
            }
            case 2 : {
                cout << "Delete an Element : ";
                cin >> value;
                A.remove(value);
                break;
            }
            case 3 : {
                cout << "Enter element to search : ";
                cin >> value;
                if(A.search(value)){
                    cout << "Yes element is present\n";
                }
                else{
                    cout << "No element is not present\n";
                }
                break;
            }
            case 4 : {
                A.print();
                break;
            }
            case 5 : {
                break;
            }
            case 6 : {
                A.printPostOrder();
                break;
            }
            case 7 :{
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