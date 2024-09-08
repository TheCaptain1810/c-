#include <iostream>
#include <thread>

using namespace std;

void function1(char symbol) {
    for (int i = 0; i < 100; ++i)
        cout << symbol;
}

void function2() {
    for (int i = 0; i < 100; ++i)
        cout << "-";
}

int main() {
    thread worker1(function1, 'o'); // Pass 'o' as a char
    thread worker2(function2);

    // Join threads to ensure they finish before the main thread exits
    worker1.join();
    worker2.join();

    return 0;
}
