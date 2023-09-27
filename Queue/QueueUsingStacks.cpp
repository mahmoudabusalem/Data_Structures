#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    stack<int> s1;  // For enQueue operation
    stack<int> s2;  // For deQueue operation

public:
    // Enqueue an element
    void enQueue(int element) {
        s1.push(element);
    }

    // Dequeue an element
    int deQueue() {
        // If s2 is empty, transfer elements from s1 to s2 to reverse the order
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // Check if s2 is still empty (queue is empty)
        if (s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        // Pop and return the front element from s2
        int element = s2.top();
        s2.pop();
        return element;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (s1.empty() && s2.empty());
    }

    // Display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            // Transfer elements from s2 to s1 to display them
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }

            // Print the front element and the rest of the elements
            cout << "Front: " << s1.top() << endl;
            while (!s1.empty()) {
                cout << s1.top() << " ";
                s2.push(s1.top());
                s1.pop();
            }
            cout << endl;
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

    // Dequeue two elements
    cout << "Dequeued Element: " << q.deQueue() << endl;
    cout << "Dequeued Element: " << q.deQueue() << endl;

    // Enqueue two more elements
    q.enQueue(6);
    q.enQueue(7);

    // Display the updated queue
    cout << "Updated Queue:\n";
    q.display();

    return 0;
}
