#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
public:
    Employee(string name, int id) : name(name), id(id) {}
    virtual void display() const {
        cout << "ID: " << id << ", Name: " << name;
    }
    virtual ~Employee() {}
};

class Manager : public Employee {
    int teamSize;
public:
    Manager(string name, int id, int teamSize) : Employee(name, id), teamSize(teamSize) {}
    void display() const override {
        Employee::display();
        cout << " | Role: Manager | Team Size: " << teamSize << endl;
    }
};

class Engineer : public Employee {
    string skill;
public:
    Engineer(string name, int id, string skill) : Employee(name, id), skill(skill) {}
    void display() const override {
        Employee::display();
        cout << " | Role: Engineer | Skill: " << skill << endl;
    }
};

int main() {
    Employee* staff[] = {
        new Manager("Alice Smith", 101, 5),
        new Engineer("Bob Jones", 102, "C++ Development")
    };

    cout << "--- Employee Directory ---\n";
    for (Employee* e : staff) {
        e->display();
        delete e;
    }

    return 0;
}