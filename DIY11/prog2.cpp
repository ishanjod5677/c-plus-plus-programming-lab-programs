
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Queue {
    T arr[100];
    int frontIndex, rear;

public:
    Queue() {
        frontIndex = 0;
        rear = -1;
    }

    void enqueue(T value) {
        if (rear == 99) {
            cout << "Queue is full!" << endl;
            return;
        }

        arr[++rear] = value;
    }

    void dequeue() {
        if (frontIndex > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Removed: " << arr[frontIndex++] << endl;
    }

    void front() {
        if (frontIndex > rear)
            cout << "Queue is empty!" << endl;
        else
            cout << "Front element: " << arr[frontIndex] << endl;
    }
};

int main() {
    Queue<string> q;

    q.enqueue("Apple");
    q.enqueue("Banana");
    q.enqueue("Mango");

    q.front();

    q.dequeue();

    q.front();

    return 0;
}