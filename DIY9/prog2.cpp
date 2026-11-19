#include <iostream>
#include <stdexcept>
using namespace std;

// Custom exception classes
class Overflow : public runtime_error {
public:
    Overflow() : runtime_error("Stack Overflow!") {}
};

class Underflow : public runtime_error {
public:
    Underflow() : runtime_error("Stack Underflow!") {}
};

// Stack class
class Stack {
private:
    int arr[5];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == 4) {
            throw Overflow();
        }

        arr[++top] = value;
        cout << value << " pushed into stack" << endl;
    }

    void pop() {
        if (top == -1) {
            throw Underflow();
        }

        cout << arr[top--] << " popped from stack" << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements: ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    Stack s;

    // Handling Overflow
    try {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        s.push(60);
    }
    catch (Overflow &e) {
        cout << "Exception: " << e.what() << endl;
    }

    s.display();

    // Handling Underflow
    try {
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
    }
    catch (Underflow &e) {
        cout << "Exception: " << e.what() << endl;
    }

    s.display();

    return 0;
}