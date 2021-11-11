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
        void print() {
            print_sub(root);
            cout << endl;
        };
        int get_size() {
            return t_size;
        }
};

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

template<typename T>
Node<T>* Tree<T>::delete_at_sub(T i, Node<T>* p) {
    if (i < p->val)
        p->pLeft = delete_at_sub(i, p->pLeft);
    else if (i > p->val)
        p->pRight = delete_at_sub(i, p->pRight);
    else if(i == p->val) {
        if ( ! p->pLeft) {
            Node<T> *temp = p->pRight;
            delete p;

            return temp;
        }
        else if ( ! p->pRight) {
            Node<T> *temp = p->pLeft;
            delete p;

            return temp;
        }
        Node<T> *temp = minValue(p->pRight);
        p->val = temp->val;
        p->pRight = delete_at_sub(p->val, p->pRight);
    }
    return p;
}

#endif // TREE_H_INCLUDED