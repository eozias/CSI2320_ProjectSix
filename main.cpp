#include<iostream>
#include "CityClock.h"

using namespace std;

int main() {
    cout << "Demonstrating the CityClock class..." << endl;

    cout << "Create a CityClock object using the default constructor" << endl;
    CityClock clock1;
    clock1.show();
    cout << "The time in 12 hour format is: " << endl;
    clock1.toggleFormat();
    clock1.show();
    cout << "Using the tick function..." << endl;
    clock1.tick();
    clock1.show();
    cout << endl;

    cout << "Create a CityClock object using the four-argument constructor" << endl;
    CityClock clock2(10, 07, 57, "Troy, Michigan");
    cout << "The time in 24 hour format is: " << endl;
    clock2.show();
    cout << "The time in 12 hour format is: " << endl;
    clock2.toggleFormat();
    clock2.show();
    cout << "Using the tick function..." << endl;
    clock2.tick();
    clock2.show();
    cout << endl;

    cout << "Create a copy of clock2 using the copy constructor" << endl;
    CityClock clock3(clock2);
    clock3.show();
    cout << endl;

    cout << "Create a new CityClock object using the move constructor" << endl;
    CityClock clock4(move(clock3));
    clock4.show();
    cout << endl;

    cout << "Assign clock2 to clock1 using the copy assignment operator" << endl;
    clock1 = clock2;
    clock1.show();
    cout << endl;

    cout << "Assign clock4 to clock2 using the move assignment operator" << endl;
    clock2 = move(clock4);
    clock2.show();
    cout << endl;

    cout << "Convert clock1 to a string using the type conversion function" << endl;
    string clock1Str = clock1;
    cout << clock1Str << endl;
    cout << endl;

    cout << "Add one hour to clock1 using the overloaded addition operator" << endl;
    CityClock clock5 = clock1 + 3600;
    clock5.show();
    cout << endl;

    cout << "Print clock5 using the overloaded ostream insertion operator" << endl;
    cout << clock5 << endl;

    return 0;
}