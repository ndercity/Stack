#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Stack {
private:
    vector<int> elements;

public:
    void push(int element) {
        elements.push_back(element);
    }

    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        }
        else {
            cout << "Stack is empty. Cannot pop element." << endl;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return elements.back();
        }
        else {
            cout << "Stack is empty." << endl;
            return -1; // Return a special value to indicate stack is empty
        }
    }

    bool isEmpty() {
        return elements.empty();
    }

    void display() {
        if (!isEmpty()) {
            cout << "Stack elements: ";
            for (int i : elements) {
                cout << i << " ";
            }
            cout << endl;
        }
        else {
            cout << "Stack is empty." << endl;
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
