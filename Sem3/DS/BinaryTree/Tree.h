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
    void print_sub(Node<T> *p);
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
        void print() {
            print_sub(root);
            cout << endl;
        };
        int get_size() {
            return t_size;
        }
        bool search(int key) {
            return searchNode(root,key);
        }
        void printPostOrder(){
            printPostorderSub(root);
        }
};

template<typename T>
void printPostorderSub(Node<T>* node) {
    if (node == NULL)
        return;
    printPostorderSub(node->pLeft);
    printPostorderSub(node->pRight);
    cout << node->val << " ";
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

template<typename T>
void Tree<T>::print_sub(Node<T> *p) {
    if(p) {
        print_sub(p->pLeft);
        cout << p->val << " ";
        print_sub(p->pRight);
    }
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
    // if(temp == NULL){
    //     printf("Tree is empty\n");
    //     return false;
    // }
    // else{
    //     if(temp->val == value) {  
    //         return true;
    //     }  
    //     if(temp->pLeft != NULL) {  
    //         searchNode(temp->pLeft, value);
    //     }
    //     if(temp->pRight != NULL) {
    //         searchNode(temp->pRight, value);
    //     }
    // }
    // return false;

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