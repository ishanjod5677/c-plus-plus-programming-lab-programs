#include <iostream>
#include <stdexcept>
using namespace std;

// Base exception class
class MathError : public runtime_error {
public:
    MathError() : runtime_error("Math Error occurred!") {}
};

// Derived exception class
class DivideByZero : public MathError {
public:
    DivideByZero() {}
};

// Division function
int divide(int a, int b) {
    if (b == 0) {
        throw DivideByZero();
    }
    return a / b;
}

int main() {

    cout << "1. Incorrect Catch Order" << endl;

    try {
        cout << divide(10, 0) << endl;
    }
    catch (MathError &e) {
        cout << "Caught MathError: " << e.what() << endl;
    }
    catch (DivideByZero &e) {
        cout << "Caught DivideByZero" << endl;
    }

    cout << "\n2. Correct Catch Order" << endl;

    try {
        cout << divide(10, 0) << endl;
    }
    catch (DivideByZero &e) {
        cout << "Caught DivideByZero exception" << endl;
    }
    catch (MathError &e) {
        cout << "Caught MathError: " << e.what() << endl;
    }

    return 0;
}