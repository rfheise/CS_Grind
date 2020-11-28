#include <thread>
#include <string>
#include <iostream>
#include <chrono>

using namespace std;

int main(void) {
    thread t = thread([]() -> void {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "should print third" << endl;
    });
    thread s = thread([]() -> void{
        cout << "should print first" << endl;
    });
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "should print second" << endl;
    t.join();
    s.join();
    
}