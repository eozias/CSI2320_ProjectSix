#include "CityClock.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

CityClock::CityClock() : Clock() {
    cityName = new char[strlen("Rochester, Michigan") + 1];
    strcpy(cityName, "Rochester, Michigan");
}

CityClock::CityClock(int h, int m, int s, const char *name) : Clock(h, m, s){
    cityName = new char[strlen(name) + 1];
    strcpy(cityName, name);
}

void CityClock::toggleFormat() {
    Clock::toggleFormat();
}

void CityClock::tick() {
    Clock::tick();
}

void CityClock::show() {
    cout << cityName << " - ";
    Clock::show();
}

CityClock::~CityClock() {
    delete[] cityName;
}

CityClock::CityClock(const CityClock &original) {
    hour = original.hour;
    minute = original.minute;
    second = original.second;
    is24HourFormat = original.is24HourFormat;
    isPM = original.isPM;
    cityName = new char[strlen(original.cityName) + 1];
    strcpy(cityName, original.cityName);
}

CityClock::CityClock(CityClock &&original) {
    hour = original.hour;
    minute = original.minute;
    second = original.second;
    is24HourFormat = original.is24HourFormat;
    isPM = original.isPM;
    cityName = original.cityName;
    // Nullify the original object's pointer
    original.cityName = nullptr;
}

CityClock &CityClock::operator=(const CityClock &original) {
    if (this != &original) {
        delete[] cityName;
        // Copy from original
        hour = original.hour;
        minute = original.minute;
        second = original.second;
        is24HourFormat = original.is24HourFormat;
        isPM = original.isPM;
        cityName = new char[strlen(original.cityName) + 1];
        strcpy(cityName, original.cityName);
    }
    return *this;
}

CityClock &CityClock::operator=(CityClock &&original) {
    if (this != &original) {
        delete[] cityName;
        // Move from original
        hour = original.hour;
        minute = original.minute;
        second = original.second;
        is24HourFormat = original.is24HourFormat;
        isPM = original.isPM;
        cityName = original.cityName;
        // Nullify the original object's pointer
        original.cityName = nullptr;
    }
    return *this;
}

CityClock::operator string() const {
    stringstream time;
    if (is24HourFormat) {
        time << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2)
             << setfill('0') << second;
    } else {
        time << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2)
             << setfill('0') << second;
        if (isPM) {
            time << " PM";
        } else {
            time << " AM";
        }
    }
    return string(cityName) + " - " + time.str();
}

CityClock CityClock::operator+(int sec) const {
    CityClock clock(*this);
    clock.second += sec;

    while (clock.second >= 60) {
        clock.second -= 60;
        clock.minute++;
    }

    while (clock.minute >= 60) {
        clock.minute -= 60;
        clock.hour++;
    }

    while (clock.hour >= 24) {
        clock.hour -= 24;
    }

    return clock;
}

ostream &operator<<(ostream &os, const CityClock &clock) {
    os << clock.cityName << " - ";
    if (clock.is24HourFormat) {
        os << setw(2) << setfill('0') << clock.hour << ":" << setw(2) << setfill('0') << clock.minute << ":" << setw(2)
           << setfill('0') << clock.second;
    } else {
        os << setw(2) << setfill('0') << clock.hour << ":" << setw(2) << setfill('0') << clock.minute << ":" << setw(2)
           << setfill('0') << clock.second;
        if (clock.isPM) {
            os << " PM";
        } else {
            os << " AM";
        }
    }
    return os;
}