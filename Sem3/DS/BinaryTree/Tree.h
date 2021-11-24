#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include "Node.h"
using namespace std;

template<typename T> 
class Tree {
    Node<T>* root;
    Node<T>* insert_at_sub(T i, Node<T>*);
    Node<T>* delete_at_sub(T i, Node<T>*);
    Node<T>* minValue(Node<T>* temp);
    bool searchNode(Node<T> *temp, int value);
    void printPreOrderSub(Node<T>* node);
    void printInOrderSub(Node<T>* node);
    void printPostOrderSub(Node<T>* node);

    int t_size = 0;

    public:
        Tree () {
            root = nullptr;
        }
        ~Tree() {
            delete root;
        }
        void add(T i) {
            ++t_size;
            root = insert_at_sub(i, root);
        }
        void remove(T i){
            delete_at_sub(i, root);
        }
        int get_size() {
            return t_size;
        }
        bool search(int key) {
            return searchNode(root,key);
        }
        void printPostOrder(){
            printPostOrderSub(root);
        }
        void printPreOrder(){
            printPreOrderSub(root);
        }void printInOrder(){
            printInOrderSub(root);
        }
};

template<typename T>
void Tree<T>::printPostOrderSub(Node<T>* node) {
    if (node == NULL)
        return;
    printPostOrderSub(node->pLeft);
    printPostOrderSub(node->pRight);
    cout << node->val << " ";
}

template<typename T>
void Tree<T>::printInOrderSub(Node<T>* node) {
    if (node == NULL)
        return;
    printInOrderSub(node->pLeft); 
    cout << node->val << " ";
    printInOrderSub(node->pRight);
}
 
template<typename T>
void Tree<T>::printPreOrderSub(Node<T>* node) {
    if (node == NULL)
        return;
    cout << node->val << " ";
    printPreOrderSub(node->pLeft);
    printPreOrderSub(node->pRight);
}

template<typename T>
Node<T>* Tree<T>::insert_at_sub(T i, Node<T> *p) {
    if( ! p )
        return new Node<T>(i);
    else if (i <= p->val)
        p->pLeft = insert_at_sub(i, p->pLeft);
    else if (i > p->val)
        p->pRight = insert_at_sub(i, p->pRight);

    return p;
}


template <typename T>
Node<T>* Tree<T>::delete_at_sub(T x, Node<T>* tree) {
    Node<T>* temp;
    if(tree == NULL)
        return NULL;
    else if(x < tree->val)
        tree->pLeft = delete_at_sub(x, tree->pLeft);
    else if(x > tree->val)
        tree->pRight = delete_at_sub(x, tree->pRight);
    else if(tree->pLeft && tree->pRight)
    {
        temp = minValue(tree->pRight);
        tree->val = temp->val;
        tree->pRight = delete_at_sub(tree->val, tree->pRight);
    }
    else
    {
        temp = tree;
        if(tree->pLeft == NULL)
            tree = tree->pRight;
        else if(tree->pRight == NULL)
            tree = tree->pLeft;
        delete temp;
    }

    return tree;
}


template<typename T>
bool Tree<T>::searchNode(Node<T> *temp, int value) {
    Node<T> *current = root;
    while(current->val != value) {
        if(current != NULL) {
            // cout << current->val;
            if(current->val > value) {
                current = current->pLeft;
            }
            else {
                current = current->pRight;
            }
            if(current == NULL) {
                return false;
            }
        }
    }
    return true;
}

template<typename T>
Node<T> * Tree<T>::minValue(Node<T> * temp) {
    if(temp == NULL)
        return NULL;
    else if(temp->pLeft == NULL)
        return temp;
    else
        return minValue(temp->pLeft);
}

#endif