#include <iostream>
#include <windows.h>

using namespace std;

int counter = 0;
HANDLE mtx;

DWORD WINAPI increment(LPVOID lpParam) {
    for (int i = 0; i < 100000; i++) {
        WaitForSingleObject(mtx, INFINITE); // Locks mutex
        counter++;
        ReleaseMutex(mtx);                  // Unlocks mutex
    }
    return 0;
}

int main() {
    mtx = CreateMutex(NULL, FALSE, NULL);

    HANDLE t1 = CreateThread(NULL, 0, increment, NULL, 0, NULL);
    HANDLE t2 = CreateThread(NULL, 0, increment, NULL, 0, NULL);

    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    CloseHandle(t1);
    CloseHandle(t2);
    CloseHandle(mtx);

    cout << "Final Counter = " << counter << endl;
    return 0;
}