#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;
public:
    Account(string accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual double calculateInterest() const = 0;
    
    virtual void display() const {
        cout << "Account: " << accountNumber << " | Balance: $" << balance;
    }
    
    virtual ~Account() {} 
};

class Savings : public Account {
    double interestRate; 
public:
    Savings(string accNum, double bal, double rate) : Account(accNum, bal), interestRate(rate) {}
    
    double calculateInterest() const override {
        return balance * (interestRate / 100.0);
    }
    
    void display() const override {
        Account::display();
        cout << " | Type: Savings (Rate: " << interestRate << "%)" << endl;
    }
};

class Current : public Account {
    double overdraftFee; 
public:
    Current(string accNum, double bal, double fee) : Account(accNum, bal), overdraftFee(fee) {}
    
    double calculateInterest() const override {
        
        return -(overdraftFee); 
    }
    
    void display() const override {
        Account::display();
        cout << " | Type: Current (Fee: $" << overdraftFee << ")" << endl;
    }
};

int main() {
    Account* accounts[] = {
        new Savings("SAV-1001", 5000.0, 4.0),
        new Current("CUR-2001", 2500.0, 15.0)
    };

    cout << "--- Processing Accounts ---" << endl;
    for (Account* acc : accounts) {
        acc->display();
        cout << "Calculated Interest/Fee: $" << acc->calculateInterest() << "\n\n";
    }
    for (Account* acc : accounts) {
        delete acc;
    }

    return 0;
}