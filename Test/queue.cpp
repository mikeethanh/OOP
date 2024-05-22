#include <iostream>

template <typename T>
class QueueNode {
public:
    T data;
    QueueNode* next;

    QueueNode(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    QueueNode<T>* front;
    QueueNode<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(T val) {
        QueueNode<T>* newNode = new QueueNode<T>(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty, cannot dequeue.\n";
            return;
        }

        QueueNode<T>* temp = front;
        front = front->next;
        delete temp;
    }

    T getFront() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty.\n";
            return T();
        }

        return front->data;
    }

    void printQueue() const {
        QueueNode<T>* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue<int> myQueue;

    // Enqueue elements into the queue
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Print the front element
    std::cout << "Front element: " << myQueue.getFront() << std::endl;

    // Dequeue an element
    myQueue.dequeue();

    // Print the front element after dequeue
    std::cout << "Front element after dequeue: " << myQueue.getFront() << std::endl;

    // Print the entire queue
    std::cout << "Queue elements: ";
    myQueue.printQueue();

    // Check if the queue is empty
    std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
