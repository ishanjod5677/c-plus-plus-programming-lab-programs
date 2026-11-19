#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    if (!fin || !fout) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    int lineNo = 1;

    while (getline(fin, line)) {
        fout << lineNo << ". " << line << endl;
        lineNo++;
    }

    cout << "File copied successfully!" << endl;

    fin.close();
    fout.close();

    return 0;
}