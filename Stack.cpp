#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int element) {
        Node* newNode = new Node;
        newNode->data = element;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        else {
            cout << "Stack is empty. Cannot pop element." << endl;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return top->data;
        }
        else {
            cout << "Stack is empty." << endl;
            return -1; // Return a special value to indicate stack is empty
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (!isEmpty()) {
            cout << "Stack elements: ";
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else {
            cout << "Stack is empty." << endl;
        }
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int getIntegerInput() {
    string input;
    int number;
    while (true) {
        getline(cin, input);
        stringstream ss(input);
        if (ss >> number && ss.eof()) {
            break;
        }
        cout << "Invalid input. Please enter a valid integer: ";
    }
    return number;
}

int main() {
    Stack myStack;
    int choice, element;

    do {
        cout << "Stack ADT Menu:" << endl;
        cout << "1. Push Element" << endl;
        cout << "2. Pop Element" << endl;
        cout << "3. Peek Element" << endl;
        cout << "4. Display Stack" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        choice = getIntegerInput();

        switch (choice) {
        case 1:
            cout << "Enter element to push: ";
            element = getIntegerInput();
            myStack.push(element);
            cout << "Element " << element << " pushed to the stack." << endl;
            break;

        case 2:
            myStack.pop();
            break;

        case 3:
            element = myStack.peek();
            if (element != -1) {
                cout << "Top element of the stack: " << element << endl;
            }
            break;

        case 4:
            myStack.display();
            break;

        case 5:
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
