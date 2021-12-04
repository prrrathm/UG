#include <iostream>
using namespace std;

template<typename T> class Node {
    public:
        Node<T> *left;
        Node<T> *right;
        T data;
        // Node
        Node<T>(T val) {
            this->data = val;
            left = right = nullptr;
        }
        Node<T> (){
            left = right = nullptr;
        }
};

template<typename T> 
class Tree {
    Node<T>* insert_at_sub(T i, Node<T>*);
    void printPreOrderSub(Node<T>* node);
    void deleteByCopying(Node<T>*& node);

    public:
        Node<T>* root;
        Tree () {
            root = nullptr;
            }
        void add(T i) {
            root = insert_at_sub(i, root);
            }
        void remove(Node<T>* n) {
            deleteByCopying(n);
            }
        void printPreOrder() {
            printPreOrderSub(root);
            }
};

int main() {
    Tree<int> *a = new Tree<int>();
    a->root = new Node<int>(1);
    a->root->left = new Node<int>(2);
    a->root->right = new Node<int>(3);
    a->root->left->left = new Node<int>(4);
    a->root->right->left = new Node<int>(5);
    a->root->right->right = new Node<int>(6);
    a->root->right->left->left = new Node<int>(7);
    a->root->right->left->right = new Node<int>(8);
    
    cout << "Tree before Deleting => ";
    a->printPreOrder();
    a->remove(a->root->right);
    cout << endl;
    
    cout << "Tree after Deleting => ";
    a->printPreOrder();
    cout << endl;
    return 0;
}

template<typename T>
void Tree<T>::printPreOrderSub(Node<T>* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreOrderSub(node->left);
    printPreOrderSub(node->right);
}

// template<typename T>
// Node<T>* Tree<T>::insert_at_sub(T i, Node<T> *p) {
//     if( ! p )
//         return new Node<T>(i);
//     else if (i <= p->data)
//         p->left = insert_at_sub(i, p->left);
//     else if (i > p->data)
//         p->right = insert_at_sub(i, p->right);
//     return p;
// }

template<typename T>
void Tree<T>::deleteByCopying(Node<T>*& node) {
    Node<T> *previous, *tmp = node;
    if (node->right == 0)
        node = node->left;

    else if (node->left == 0)
        node = node->right;
    else {
        tmp = node->left;
        previous = node;
        while (tmp->right != 0) {
            previous = tmp;
            tmp = tmp->right;
            }
        node->data = tmp->data;
        if (previous == node)
            previous ->left = tmp->left;
        else 
            previous ->right = tmp->left; 
        }
    delete tmp;
}

