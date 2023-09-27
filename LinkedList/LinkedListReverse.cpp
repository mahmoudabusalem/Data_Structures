#include <iostream>

template <class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T data) : data(data), next(nullptr) {}
};

template <class T>
class LinkedList {
private:
    Node<T> *head;

public:
    LinkedList() : head(nullptr) {}

    // Function to add an element to the end of the linked list
    void pushBack(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T> *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to reverse the linked list
    void reverse() {
        Node<T> *prev = nullptr;
        Node<T> *current = head;
        Node<T> *nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next; // Store the next node
            current->next = prev;     // Reverse the current node's pointer
            prev = current;          // Move prev to the current node
            current = nextNode;      // Move current to the next node
        }

        head = prev; // Update the head to the last node (new first node)
    }

    // Function to print the linked list
    void print() const {
        Node<T> *current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<int> myList;

    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);
    myList.pushBack(4);
    myList.pushBack(5);

    std::cout << "Original Linked List: ";
    myList.print();

    myList.reverse();

    std::cout << "Reversed Linked List: ";
    myList.print();

    return 0;
}
