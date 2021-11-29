#include <iostream>
#include <stack>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Iterative function to perform postorder traversal on the tree
void postorderIterative(Node* root) {
    if (root == nullptr) {
        return;
    }
    stack<Node*> s;
    s.push(root);
    stack<int> out;
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop(); 
        out.push(curr->data);
        if (curr->left) {
            s.push(curr->left);
        } 
        if (curr->right) {
            s.push(curr->right);
        }
    }
    while (!out.empty()) {
        cout << out.top() << " ";
        out.pop();
    }
}
 
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
    Tree<int> tr = new Tree<int>();
    Node* root = new Node<int>(1);
    tr->root->left = new Node<int>(2);
    tr->root->right = new Node<int>(3);
    tr->root->left->left = new Node<int>(4);
    tr->root->right->left = new Node<int>(5);
    tr->root->right->right = new Node<int>(6);
    tr->root->right->left->left = new Node<int>(7);
    tr->root->right->left->right = new Node<int>(8);
 
    // postorderIterative(root);
 /""
 
 
 
    tr.printPostOrder();
    
 
    return 0;
}