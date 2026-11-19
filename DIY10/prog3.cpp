#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int marks;

    void display() {
        cout << "Name: " << name
             << ", Marks: " << marks << endl;
    }
};

int main() {
    Student s[100];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    ofstream fout("students.txt");

    if (!fout) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter name and marks: ";
        cin >> s[i].name >> s[i].marks;

        fout << s[i].name << " "
             << s[i].marks << endl;
    }

    fout.close();

    ifstream fin("students.txt");

    if (!fin) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int i = 0;

    while (i < n && fin >> s[i].name >> s[i].marks) {
        i++;
    }

    cout << "\nStudent Records:\n";

    for (int j = 0; j < i; j++) {
        s[j].display();
    }

    if (i > 0) {
        int topper = 0;

        for (int j = 1; j < i; j++) {
            if (s[j].marks > s[topper].marks) {
                topper = j;
            }
        }

        cout << "\nTopper:\n";
        s[topper].display();
    }

    fin.close();

    return 0;
}