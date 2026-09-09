#include<iostream>
#include<string>
#include<cctype> 
using namespace std;

int main() {
    string a;
    cout<<"Enter a word :";
    cin>>a;
    cout<<"length : "<<a.length()<<endl;
    cout<<"upper : ";
    for(char c:a) cout<<(char)toupper(c);
    cout<< endl;

    bool pal = true;
    for(size_t i = 0, j = a.size() - 1; i < j; ++i, --j)
        if(a[i] != a[j]) { pal = false; break; }
    cout<<a<<" "<<(pal ? "IS " : "IS NOT ")<<"a palindrome \n";

    size_t pos = a.find("an");
    if(pos != string :: npos) cout<<"an found at index "<< pos <<endl;
    else cout<<"an not found \n";
    return 0;

}