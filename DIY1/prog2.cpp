//anagram test
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool areAnagrams(string w1, string w2) {
    if (w1.length() != w2.length()) return false;
    
    // Sort both words
    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());
    
    return w1 == w2;
}

int main() {
    string word1, word2;
    cout << "Enter first word: ";
    cin >> word1;
    cout << "Enter second word: ";
    cin >> word2;

    if (areAnagrams(word1, word2)) {
        cout << "Result: The words are anagrams." << endl;
    } else {
        cout << "Result: The words are NOT anagrams." << endl;
    }

    return 0;
}