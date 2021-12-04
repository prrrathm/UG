// Implement a stack using Array representation

#include<iostream>
using namespace std;

template <typename T, int size>
class Stack {
    private:
        T* stack; 
        int top;   

    public:
        Stack(){
            stack = new T[size];
            top = -1;
        }
        ~Stack(){
            delete[] stack;
        }
        bool is_empty(){
            return top == -1;
        }  
        void push(T element){
            if (top == size - 1) {
                throw out_of_range("Stack Overflow!! No more space to add elements.");
            }
            stack[++top] = element; 
        }
        T pop(){
            if (is_empty()) {
                throw out_of_range("Stack Underflow!! No more element to pop.");
            }
            T element_popped = stack[top--];
            return element_popped;
        }  
        void display(){
            if (is_empty()) {
                cout << "Woops! stack is empty." << endl;
                return;
            }
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
        T get_top_element(){
            if (is_empty()) {
                throw out_of_range("Stack is empty!!");
            }
            return stack[top];
        } 
        void clear(){
            delete[] stack;
            top = -1;
            stack = new T[size];
        }
};

int main(){
    Stack<int,6> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    cout << "Stack before popping 2 elements : ";
    a.display();
    a.pop();
    a.pop();
    cout << "Stack after popping 2 elements : ";
    a.display();

    cout << "Top Element :" << a.get_top_element();
    cout << "\nClearing the Stack\n";
    a.clear();
    if (a.is_empty()) 
        cout << "Stack is now empty";
    else
        cout << "Stack is not empty";
    
    cout << endl;
    return 0;    
}
