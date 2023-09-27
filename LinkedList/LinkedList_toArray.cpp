#include <iostream>
#include <vector>

// Node class to represent elements in the linked list
template <class T>
class Node {
public:
    T data;
    Node<T> *next;

    // Constructor to initialize a node with data and a null next pointer
    Node(T data) : data(data), next(nullptr) {}
};

// Linked List class
template <class T>
class LinkedList {
private:
    Node<T> *head;

public:
    // Constructor to initialize an empty linked list with a null head
    LinkedList() : head(nullptr) {}

    // Function to add an element to the end of the linked list
    void pushBack(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr) {
            // If the list is empty, make the new node the head
            head = newNode;
        } else {
            Node<T> *current = head;
            while (current->next != nullptr) {
                // Traverse the list to find the last node
                current = current->next;
            }
            // Add the new node to the end
            current->next = newNode;
        }
    }

    // Function to convert the linked list to an array
    std::vector<T> toArray() const {
        std::vector<T> result;  // Create a vector to store the elements
        Node<T> *current = head;
        while (current != nullptr) {
            // Traverse the linked list
            result.push_back(current->data);  // Add each element to the vector
            current = current->next;
        }
        return result;
    }
};

int main() {
    // Create a new linked list
    LinkedList<int> myList;

    // Add some elements to the list
    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);
    myList.pushBack(4);
    myList.pushBack(5);

    // Convert the linked list to an array
    std::vector<int> myArray = myList.toArray();

    // Print the array
    std::cout << "Array: ";
    for (int num : myArray) {
        // Iterate through the array and print each element
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
