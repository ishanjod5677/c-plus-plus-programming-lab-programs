#include <iostream>
#include <stdexcept>
using namespace std;

// Custom exception class
class InsufficientFunds : public runtime_error {
public:
    InsufficientFunds(string msg) : runtime_error(msg) {}
};

// BankAccount class
class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds("Insufficient balance!");
        }

        if (amount <= 0) {
            throw invalid_argument("Invalid withdrawal amount!");
        }

        balance -= amount;
        cout << "Amount withdrawn: " << amount << endl;
    }

    void display() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account(5000);

    account.display();

    try {
        account.withdraw(6000);
    }
    catch (InsufficientFunds &e) {
        cout << "Exception: " << e.what() << endl;
    }
    catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    account.display();

    return 0;
}