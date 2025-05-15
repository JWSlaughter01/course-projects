#include "Date.h"
#include <iostream>
using namespace std;

void Date::set(int month_, int day_, int year_, int hour_) {
    month = month_;
    day = day_;
    year = year_;
    hour = hour_;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

int Date::getHour() const {
    return hour;
}

void Date::print() const{
    static const string months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    cout << months[month] << " " << day << ", " << year << ", ";
    cout << hour << ":00";
}
