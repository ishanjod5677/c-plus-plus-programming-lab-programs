#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string name) : name(name) {
        cout << "Person constructor called for: " << name << endl;
    }
    void displayPerson() const {
        cout << "Name: " << name << endl;
    }
};

// Virtual inheritance ensures only one copy of Person exists
class Student : virtual public Person {
protected:
    int studentID;
public:
    Student(string name, int sID) : Person(name), studentID(sID) {
        cout << "Student constructor called.\n";
    }
};

class Employee : virtual public Person {
protected:
    int empID;
public:
    Employee(string name, int eID) : Person(name), empID(eID) {
        cout << "Employee constructor called.\n";
    }
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(string name, int sID, int eID) 
        : Person(name), Student(name, sID), Employee(name, eID) {
        cout << "TeachingAssistant constructor called.\n";
    }

    void displayTA() const {
        displayPerson(); 
        cout << "Student ID: " << studentID << endl;
        cout << "Employee ID: " << empID << endl;
    }
};

int main() {
    cout << "Creating TeachingAssistant object:\n";
    TeachingAssistant ta("Charlie Brown", 9001, 405);
    
    cout << "\n--- TA Details ---\n";
    ta.displayTA();

    return 0;
}