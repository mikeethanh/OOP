#include <iostream>

template <typename T>
class StackNode {
public:
    T data;
    StackNode* next;

    StackNode(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    StackNode<T>* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void push(T val) {
        StackNode<T>* newNode = new StackNode<T>(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty, cannot pop.\n";
            return;
        }

        StackNode<T>* temp = top;
        top = top->next;
        delete temp;
    }

    T getTop() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty.\n";
            return T();
        }

        return top->data;
    }
};

int main() {
    Stack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Print the top element
    std::cout << "Top element: " << myStack.getTop() << std::endl;

    // Pop an element
    myStack.pop();

    // Print the top element after popping
    std::cout << "Top element after pop: " << myStack.getTop() << std::endl;

    // Check if the stack is empty
    std::cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
