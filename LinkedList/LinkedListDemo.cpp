#include <iostream>

// Define a Node class to represent individual elements in the linked list.
template <class T>
class Node {
public:
    T data;          // Data stored in the node.
    Node<T> *next;   // Pointer to the next node.

    // Constructor to initialize a node with data and a null next pointer.
    Node(T data) : data(data), next(nullptr) {}
};

// Define a LinkedList class to represent the linked list itself.
template <class T>
class LinkedList {
private:
    Node<T> *head;   // Pointer to the head (first node) of the linked list.
    int size;        // Size of the linked list.

public:
    // Constructor to initialize an empty linked list.
    LinkedList() : head(nullptr), size(0) {}

    // Method to add an element to the front of the linked list.
    void pushFront(T data) {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Method to add an element to the back of the linked list.
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
        size++;
    }

    // Method to remove the front element from the linked list.
    void popFront() {
        if (head == nullptr) {
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    // Method to remove the back element from the linked list.
    void popBack() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node<T> *current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        size--;
    }

    // Method to access the front element.
    T &front() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    // Method to access the back element.
    T &back() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        Node<T> *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        return current->data;
    }

    // Method to check if the linked list is empty.
    bool empty() const {
        return head == nullptr;
    }

    // Method to get the size of the linked list.
    int getSize() const {
        return size;
    }

    // Method to print the elements of the linked list.
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
    // Create a new linked list
    LinkedList<int> myList;

    // Add some elements to the list
    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);
    myList.pushFront(0);

    // Print the list
    std::cout << "My List: ";
    myList.print();

    // Access the front and back elements
    try {
        std::cout << "Front Element: " << myList.front() << std::endl;
        std::cout << "Back Element: " << myList.back() << std::endl;
    } catch (const std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Remove some elements from the list
    myList.popFront();
    myList.popBack();

    // Print the updated list
    std::cout << "Updated List: ";
    myList.print();

    // Get the size of the list
    std::cout << "List Size: " << myList.getSize() << std::endl;

    return 0;
}
