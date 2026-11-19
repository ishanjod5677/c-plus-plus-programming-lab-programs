#include <iostream>
#include <string>
using namespace std;

class Logger { // only ONE instance ever
    Logger() {} // private constructor
public:
    Logger(const Logger&) = delete; // no copies
    void operator=(const Logger&) = delete;

    static Logger& get() {
        static Logger instance; // thread-safe since C++11
        return instance;        // created once, on first call
    }

    void log(const string &m) { cout << "[LOG] " << m << endl; }
};

int main() {
    Logger::get().log("system up");
    Logger::get().log("same single instance");
    return 0;
}