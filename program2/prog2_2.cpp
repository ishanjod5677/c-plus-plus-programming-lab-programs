#include<iostream>
#include<string>
using namespace std;

void logMsg(const string &Msg , int level = 1) {
    const string tag[] = {" ","INFO","WARN","ERROR"};
    cout<<"[" << tag[level] << "]" <<Msg<<endl;
}
 double interest(double principle,double years,double rate=7.5)
 {
    return principle*rate*years/100.0;
 }

 int main() {
    logMsg("system started");
    logMsg("low memory",2);
    cout<<"interest = " << interest(10000,2)<<endl;
    cout<<"interest = " << interest(10000,2,9.0) <<endl;
    return 0;
 }