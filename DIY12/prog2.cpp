#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    int n, num;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the numbers:\n";

    for (int i = 0; i < n; i++) {
        cin >> num;
        pq.push(num);
    }

    if (n < 3) {
        cout << "Enter at least 3 numbers!" << endl;
        return 0;
    }

    cout << "\nThree largest numbers:\n";

    for (int i = 0; i < 3; i++) {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}