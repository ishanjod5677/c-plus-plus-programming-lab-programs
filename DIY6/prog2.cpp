#include <iostream>
#include <cstdlib>

using namespace std;

class Fraction {
private:
    int numerator, denominator;

    // Custom GCD function compatible with all C++ standards
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        if (denominator < 0) {
            long long n = numerator;
            long long d = denominator;
            numerator = -n;
            denominator = -d;
        }

        long long g = gcd(abs((long long)numerator), abs((long long)denominator));
        
        if (g != 0) {
            numerator /= g;
            denominator /= g;
        }
    }

public:
    Fraction(int n = 0, int d = 1) {
        if (d == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }

        numerator = n;
        denominator = d;
        simplify();
    }

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }

    friend istream& operator>>(istream& in, Fraction& f) {
        int n, d;
        char slash;

        if (in >> n >> slash >> d) {
            if (slash != '/' || d == 0) {
                in.setstate(ios::failbit);
                return in;
            }

            f.numerator = n;
            f.denominator = d;
            f.simplify();
        }

        return in;
    }
};

int main() {
    Fraction f1(6, 8);

    cout << "Simplified fraction: " << f1 << endl;

    Fraction f2;

    cout << "Enter a fraction (numerator/denominator): ";
    if (cin >> f2) {
        cout << "Simplified fraction: " << f2 << endl;
    } else {
        cout << "Invalid fraction!" << endl;
    }

    return 0;
}