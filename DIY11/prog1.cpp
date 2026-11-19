#include <iostream>
using namespace std;

template <typename T>
void swapVals(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    return maxVal;
}

int main() {
    int a = 10, b = 20;

    cout << "Before swapping: " << a << " " << b << endl;
    swapVals(a, b);
    cout << "After swapping: " << a << " " << b << endl;

    int arr[] = {10, 30, 20, 50, 40};
    cout << "Maximum integer: " << findMax(arr, 5) << endl;

    double x = 2.5, y = 4.5;
    swapVals(x, y);

    cout << "After swapping doubles: " << x << " " << y << endl;

    double d[] = {2.5, 8.5, 4.5, 6.5};
    cout << "Maximum double: " << findMax(d, 4) << endl;

    return 0;
}