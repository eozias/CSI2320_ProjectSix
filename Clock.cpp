#include "Clock.h"
#include <iostream>
#include <iomanip>

using namespace std;

Clock::Clock() {
    hour = 0;
    minute = 0;
    second = 0;
    is24HourFormat = true;
    isPM = false;
}

Clock::Clock(int h, int m, int s) {
    is24HourFormat = true;
    isPM = false;
    if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
        hour = h;
        minute = m;
        second = s;
    } else {
        cout << "Invalid input. Setting time to 00:00:00" << endl;
        hour = 0;
        minute = 0;
        second = 0;
    }
}

void Clock::toggleFormat() {
    if (is24HourFormat == true) {
        // Switch to 12-hour format
        is24HourFormat = false;
        if (hour > 12) {
            hour -= 12;
            isPM = true;
        } else if (hour == 12) {
            isPM = true;
        } else if (hour == 0) {
            hour = 12;
            isPM = false;
        } else {
            isPM = false;
        }
    } else {
        // Switch to 24-hour format
        is24HourFormat = true;
        if (hour == 12 && isPM == false) {
            hour = 0;
        }
        else if (hour == 12 && isPM == true) {
            hour = 12;
        }
        else if (isPM == true) {
            hour += 12;
        }
    }
}

void Clock::tick() {
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
            }
        }
    }
}

void Clock::show() {
    if (is24HourFormat == true) {
        cout << setw(2) << setfill('0') << hour << ":"
                  << setw(2) << setfill('0') << minute << ":"
                  << setw(2) << setfill('0') << second << endl;
    } else {
        cout << setw(2) << setfill('0') << hour << ":"
                  << setw(2) << setfill('0') << minute << ":"
                  << setw(2) << setfill('0') << second
                  << (isPM ? " PM" : " AM") << endl;
    }
}