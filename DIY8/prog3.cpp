#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base constructor\n"; }
    virtual ~Base() { 
        cout << "Base destructor\n"; 
    }
};

class Derived : public Base {
    int* heavyData; 
public:
    Derived() {
        heavyData = new int[1000]; 
        cout << "Derived constructor: allocated memory\n";
    }
    
    ~Derived() {
        delete[] heavyData; 
        cout << "Derived destructor: freed memory\n";
    }
};

int main() {
    cout << "--- Creating object via Base pointer ---\n";
    Base* ptr = new Derived();

    cout << "\n--- Deleting object ---\n";
    delete ptr; 

    return 0;
}