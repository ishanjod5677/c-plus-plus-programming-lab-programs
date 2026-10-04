#include <iostream>
using namespace std;

class point {
    int x, y;
public:
    point(int x = 0, int y = 0) : x(x), y(y) {}

    
    point add(const point &p) const { 
        return point(x + p.x, y + p.y); 
    }

    
    point& setX(int v) { this->x = v; return *this; }
    point& setY(int v) { this->y = v; return *this; }

    void show() const { cout << "(" << x << "," << y << ")\n"; }
};

void shift(point &p) { p.setX(99); }
void tryshift(point p) { p.setX(-1); }

int main() {
    point a(1, 2), b(3, 4);

    point c = a.add(b);
    c.show();

    
    point d; 
    d.setX(7).setY(8);
    d.show();

    
    shift(a); 
    a.show();

    tryshift(b); 
    b.show();

    return 0;
}