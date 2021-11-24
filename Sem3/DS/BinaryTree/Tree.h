#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include "Node.h"
using namespace std;

template<typename T> 
class Tree {
    Node<T>* root;
    Node<T>* insert_at_sub(T i, Node<T>*);
    Node<T>* minValue(Node<T>* temp);
    Node<T>* removebst(Node<T> *root,int data);
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
            removebst(root,i);
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
    printPostOrderSub(node->left);
    printPostOrderSub(node->right);
    cout << node->data << " ";
}

template<typename T>
void Tree<T>::printInOrderSub(Node<T>* node) {
    if (node == NULL)
        return;
    printInOrderSub(node->left); 
    cout << node->data << " ";
    printInOrderSub(node->right);
}
 
template<typename T>
void Tree<T>::printPreOrderSub(Node<T>* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreOrderSub(node->left);
    printPreOrderSub(node->right);
}

template<typename T>
Node<T>* Tree<T>::insert_at_sub(T i, Node<T> *p) {
    if( ! p )
        return new Node<T>(i);
    else if (i <= p->data)
        p->left = insert_at_sub(i, p->left);
    else if (i > p->data)
        p->right = insert_at_sub(i, p->right);

    return p;
}

template <typename T>
Node<T>* Tree<T>::removebst(Node<T> *root,int data) {
    if(root==NULL) {
        return 0;
    }
    if(root->data > data) {
        root->left=removebst(root->left,data);
    }
    else if(root->data<data) {
        root->right=removebst(root->right,data);
    }
    else{
        if(root->left==NULL&&root->right==NULL) {
            delete root;
            return NULL;
        }
        else if(root->left==NULL) {
            Node<T>* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL) {
            Node<T>*temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node<T> *min= minValue(root->right);
            root->data=min->data;
            root->right=removebst(root->right,min->data);
        }
    }
    return root;
}

template<typename T>
bool Tree<T>::searchNode(Node<T> *temp, int value) {
    Node<T> *current = root;
    while(current->data != value) {
        if(current != NULL) {
            // cout << current->data;
            if(current->data > value) {
                current = current->left;
            }
            else {
                current = current->right;
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
    else if(temp->left == NULL)
        return temp;
    else
        return minValue(temp->left);
}

#endif