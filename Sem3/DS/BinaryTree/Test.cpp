# include <iostream>
#include <stack>
#include <queue>
#include <stack>
#include <variant>
using namespace std;

template<typename T> 
class Node {
    public:
        Node<T> *left;
        Node<T> *right;
        T data;
        // Node
        Node<T>(T val) {
            this->data = val;
            left = right = nullptr;
        }
};

template<typename T> 
class Tree {
    Node<T>* root;
    Node<T>* insert_at_sub(T i, Node<T>*);
    void iterativePostorder(Node<T>* node);
    int t_size = 0;

    public:
        Tree () {
            root = nullptr;
        }
        void add(T i) {
            ++t_size;
            root = insert_at_sub(i, root);
        }
        void printPostOrder(){
            iterativePostorder(root);
        }
};

template<class T>
void Tree<T>::iterativePostorder(Node<T>* node) {
    stack<Node<T>*> trav;
    Node<T>* p = root, *q = root;
    while (p != 0) {
        for ( ; p->left != 0; p = p->left)
            trav.push(p);
        while (p->right == 0 || p->right == q) {
            visit(p);
            q = p;
            if (trav.empty())
                return;
            p = trav.pop();
        }
        trav.push(p);
        p = p->right;
    }
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


int main(){
    Tree<int> example;
    example.add(12);
    example.add(34);
    example.add(54);
    example.add(76);
    example.add(1);
    example.printPostOrder();
    return 0;
}