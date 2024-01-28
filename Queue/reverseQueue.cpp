#include <iostream>
#include <stack>
using namespace std;
#define SIZE 5

class Queue {
private:
    int items[SIZE];
    int front, rear;

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
            cout << "Queue is full\n";
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            items[rear] = element;
            cout << "Inserted " << element << endl;
        }
    }

    // Function to dequeue an element from the queue
    int deQueue() {
        int element;
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return (-1);
        } else {
            element = items[front];
            if (front >= rear) {
                front = -1;
                rear = -1;
            } else {
                front++;
            }
            cout << "Deleted " << element << endl;
            return (element);
        }
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Empty Queue\n";
        } else {
            cout << "Front index: " << front << endl;
            for (int i = front; i <= rear; i++) {
                cout << items[i] << " ";
            }
            std::cout << std::endl << "Rear index: " << rear << std::endl;
        }
    }

    // Function to reverse the queue using a stack
    void reverseQueue(Queue& q) {
        stack<int> s;
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

    // Display the initial queue
    cout << "Initial Queue:\n";
    q.display();

    // Dequeue an element and display
    q.deQueue();
    cout << "Queue after dequeuing:\n";
    q.display();

    // Reverse the queue and display
    q.reverseQueue(q);
    cout << "Reversed Queue:\n";
    q.display();

    return 0;
}
