// Binary Search Tree with following Operations
// (i) Insert an element x
// (ii) Delete an element x
// (iii) Search for an element x in the BST and change its value to y and then place the node with value y at its appropriate position in the BST
// (iv) Display the elements of the BST in preorder, inorder, and postorder traversal

#include <iostream>
#include "Tree.h"
using namespace std;

class Test {
    string name;
    public:
        Test () {}
        Test(string name_) : name(name_) {}
        friend ostream& operator<<(ostream& os, Test& t) {
            os << t.name;
            return os;
        }
        bool operator<(Test t);
        bool operator<=(Test t);
        bool operator>(Test t);
};

int main() {
    Tree<int> tr;
    tr.add(4);
    tr.add(6);
    tr.add(1);
    tr.add(9);
    tr.add(2);
    tr.add(0);
    tr.add(89);
    tr.add(12);
    tr.add(32);
    tr.add(5);
    tr.add(22);
    tr.add(222);
    tr.print();
    return 0;
}