#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template<typename T> class Node {
    public:
        Node<T> *pLeft;
        Node<T> *pRight;
        T val;

        Node<T>(T val) {
            this->val = val;
            pLeft = pRight = nullptr;
        }

    // Node<T>(const Node<T>& src); -> to be implemented
    // Node& operator=(const Node&); -> to be implemented
};


#endif // NODE_H_INCLUDED