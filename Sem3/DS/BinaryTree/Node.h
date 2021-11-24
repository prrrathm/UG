#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

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
};


#endif // NODE_H_INCLUDED