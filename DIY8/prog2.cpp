#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
public:
    virtual void write(const string& message) = 0; 
    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void write(const string& message) override {
        cout << "[CONSOLE LOG]: " << message << endl;
    }
};

class FileLogger : public Logger {
    string filename;
public:
    FileLogger(string fname) : filename(fname) {}
    
    void write(const string& message) override {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << "[FILE LOG]: " << message << endl;
            file.close();
            cout << "[System]: Message written to file '" << filename << "'\n";
        } else {
            cout << "[Error]: Could not open log file!\n";
        }
    }
};

int main() {
    Logger* activeLogger = nullptr;

    bool useFile = true; 

    if (useFile) {
        activeLogger = new FileLogger("app.log");
    } else {
        activeLogger = new ConsoleLogger();
    }
    activeLogger->write("Application started successfully.");
    activeLogger->write("User logged in with ID: 404.");

    delete activeLogger;
    return 0;
}