#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string color;
public:
    Shape(string c) : color(c) {
        cout << "[Shape Constructor] Color set to: " << color << endl;
    }
    virtual ~Shape() {}
};

class Polygon : public Shape {
protected:
    int numSides;
public:
    Polygon(string c, int sides) : Shape(c), numSides(sides) {
        cout << "[Polygon Constructor] Number of sides set to: " << numSides << endl;
    }
};

class Rectangle : public Polygon {
    double length, width;
public:
    Rectangle(string c, int sides, double l, double w) : Polygon(c, sides), length(l), width(w) {
        cout << "[Rectangle Constructor] Dimensions set to: " << length << "x" << width << endl;
    }

    void display() const {
        cout << "\n--- Rectangle Final Details ---\n";
        cout << "Color: " << color << "\nSides: " << numSides 
             << "\nLength: " << length << "\nWidth: " << width << endl;
    }
};

int main() {
    cout << "Instantiating Rectangle:\n";
    Rectangle rect("Blue", 4, 10.5, 5.0);
    rect.display();

    return 0;
}