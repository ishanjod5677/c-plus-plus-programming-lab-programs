#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {2, 3, 4, 5};

    int product = accumulate(
        v.begin(),
        v.end(),
        1,
        [](int a, int b) {
            return a * b;
        }
    );

    cout << "Product of elements = " << product << endl;

    return 0;
}