#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("nums.txt");

    if (!fin) {
        cout << "Unable to open file!" << endl;
        return 1;
    }

    int num, count = 0, sum = 0;
    int minVal, maxVal;

    if (!(fin >> num)) {
        cout << "File is empty!" << endl;
        return 0;
    }

    minVal = maxVal = num;
    count++;
    sum += num;

    while (fin >> num) {
        count++;
        sum += num;

        if (num < minVal)
            minVal = num;

        if (num > maxVal)
            maxVal = num;
    }

    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;
    cout << "Minimum = " << minVal << endl;
    cout << "Maximum = " << maxVal << endl;

    fin.close();
    return 0;
}