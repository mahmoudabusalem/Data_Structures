#include <iostream>

#define MAX_SIZE 100

using namespace std;

// Initialize the stack and top pointer
int stack[MAX_SIZE];
int top = -1;

// Function to push an item onto the stack
void push(int item) {
    // Check for stack overflow
    if (top >= MAX_SIZE - 1) {
        cout << "Stack overflow\n";
        return;
    }
    top++;
    stack[top] = item;
}

// Function to pop an item from the stack
int pop() {
    // Check for stack underflow
    if (top == -1) {
        cout << "Stack underflow\n";
        return -1;
    }
    int item = stack[top];
    top--;
    return item;
}

// Function to peek at the top item without removing it
int peek() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return -1;
    }
    return stack[top];
}

// Function to clear the stack
void clear() {
    top = -1;
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to print the elements in the stack
void print_stack() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Elements in the stack: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    int n;
    cin >> n;
    int arr[n];

    // Input an array of integers
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        // Menu for stack operations
        cout << "\nStack Operations:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Clear\n";
        cout << "5. Check if empty\n";
        cout << "6. Print Stack\n";
        cout << "7. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int item;
                cout << "Enter item to push: ";
                cin >> item;
                push(item);
                break;
            case 2:
                cout << "Popped item: " << pop() << endl;
                break;
            case 3:
                cout << "Top item (peek): " << peek() << endl;
                break;
            case 4:
                clear();
                cout << "Stack cleared.\n";
                break;
            case 5:
                cout << "Stack is " << (isEmpty() ? "empty" : "not empty") << endl;
                break;
            case 6:
                print_stack();
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
