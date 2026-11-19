#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<string, int>> v = {
        {"Anu", 85},
        {"Ravi", 95},
        {"Priya", 75},
        {"Kiran", 90}
    };

    sort(v.begin(), v.end(),
         [](pair<string, int> a, pair<string, int> b) {
             return a.second < b.second;
         });

    cout << "Sorted records:\n";

    for (auto p : v) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}