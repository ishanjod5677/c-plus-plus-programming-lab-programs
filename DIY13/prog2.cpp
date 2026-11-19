#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Shape {
public:
    virtual void area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;

public:
    Circle(double radius) {
        r = radius;
    }

    void area() override {
        cout << "Area of Circle = " << 3.14 * r * r << endl;
    }
};

class Rectangle : public Shape {
    double l, b;

public:
    Rectangle(double length, double breadth) {
        l = length;
        b = breadth;
    }

    void area() override {
        cout << "Area of Rectangle = " << l * b << endl;
    }
};

class Triangle : public Shape {
    double b, h;

public:
    Triangle(double base, double height) {
        b = base;
        h = height;
    }

    void area() override {
        cout << "Area of Triangle = " << 0.5 * b * h << endl;
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;

    int n;
    cout << "Enter number of shapes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string type;

        cout << "\nEnter shape (circle/rectangle/triangle): ";
        cin >> type;

        if (type == "circle") {
            double r;
            cout << "Enter radius: ";
            cin >> r;

            shapes.push_back(make_unique<Circle>(r));
        }

        else if (type == "rectangle") {
            double l, b;
            cout << "Enter length and breadth: ";
            cin >> l >> b;

            shapes.push_back(make_unique<Rectangle>(l, b));
        }

        else if (type == "triangle") {
            double b, h;
            cout << "Enter base and height: ";
            cin >> b >> h;

            shapes.push_back(make_unique<Triangle>(b, h));
        }

        else {
            cout << "Invalid shape!" << endl;
        }
    }

    cout << "\nShape Areas:\n";

    for (auto &s : shapes) {
        s->area();
    }

    return 0;
}