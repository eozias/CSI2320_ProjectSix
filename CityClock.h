#ifndef CITYCLOCK_H
#define CITYCLOCK_H
#include <string>
#include "Clock.h"

using namespace std;

class CityClock : public Clock{
private:
    char* cityName;

public:
    // Default constructor
    CityClock();

    // Constructor
    CityClock(int, int, int, const char*);

    // Switches between 12-hour and 24-hour format based on the value of is24HourFormat
    void toggleFormat();

    // Prints out the current time in the format "HH:MM:SS" or "HH:MM:SS AM/PM"
    void show();

    // Advances the time by one second
    void tick();

    // Destructor
    ~CityClock();

    // Copy constructor
    CityClock(const CityClock&);

    // Move constructor
    CityClock(CityClock&&);

    // Copy assignment operator
    CityClock& operator=(const CityClock&);

    // Move assignment operator
    CityClock& operator=(CityClock&&);

    // Type Conversion Function
    operator string() const;

    // Overloaded Addition Operator
    CityClock operator+(int) const;

    // Overloaded ostream Operator
    friend ostream& operator<<(ostream&, const CityClock&);
};

#endif