// reverse the words
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    stringstream ss(s);
    string word;
    vector<string> words;

    // Extract words one by one
    while (ss >> word) {
        words.push_back(word);
    }

    cout << "Reversed word order: ";
    // Print words from the end of the vector to the beginning
    for (int i = words.size() - 1; i >= 0; --i) {
        cout << words[i];
        if (i > 0) {
            cout << " "; // Add space between words
        }
    }
    cout << endl;

    return 0;
}