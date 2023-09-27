#include <iostream>
#include <stack>

#define SIZE 5

class Queue {
private:
    int items[SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == 0 && rear == SIZE - 1);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to enqueue an element into the queue
    void enQueue(int element) {
        if (isFull()) {
            std::cout << "Queue is full\n";
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            items[rear] = element;
            std::cout << "Inserted " << element << std::endl;
        }
    }

    // Function to dequeue an element from the queue
    int deQueue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        } else {
            int element = items[front];
            if (front >= rear) {
                front = -1;
                rear = -1;
            } else {
                front++;
            }
            std::cout << "Deleted " << element << std::endl;
            return element;
        }
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Empty Queue\n";
        } else {
            std::cout << "Front index: " << front << std::endl;
            for (int i = front; i <= rear; i++) {
                std::cout << items[i] << " ";
            }
            std::cout << std::endl << "Rear index: " << rear << std::endl;
        }
    }

    // Function to reverse the queue using a stack
    void reverseQueue(Queue &q) {
        std::stack<int> s;
        while (!q.isEmpty()) {
            s.push(q.front());
            q.deQueue();
        }
        while (!s.empty()) {
            q.enQueue(s.top());
            s.pop();
        }
    }
};

int main() {
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);
    q.display();
    q.deQueue();
    q.display();
    return 0;
}
