#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

void Date::set(int month_, int day_, int year_, int hour_) {
    month = month_;
    day = day_;
    year = year_;
    hour = hour_;
}

/*
overloaded < relational operator. (d1 < d2) is true if and only if date d2 comes after date d1 chronologically. For example, (03/08/2200/23) < (03/09/2200/00)
*/
bool Date::operator<(const Date & rhs) {
    if (year != rhs.year) {
        return year < rhs.year;
    }
    if (month != rhs.month) {
        return month < rhs.month;
    }
    if (day != rhs.day) {
        return day < rhs.day;
    }
    // if (hour < rhs.hour) {
    //     return true;
    // }
    
    return hour < rhs.hour;
}
/*
 overloaded == relational operator. (d1 == d2) is true if and only if the month, day, year and hour are equal
*/
bool Date::operator==(const Date & rhs) {
    return (month == rhs.month && day == rhs.day && year == rhs.year && hour == rhs.hour);
}


/*
overloaded <= relational operator. (d1 <= d2) is true if and only if (d1 == d2) is true, or (d1 < d2) is true
*/
bool Date::operator<=(const Date & rhs) {
    return (*this < rhs || *this == rhs);
}

/*
overloaded – operator. If d2 > d1, (d2 – d1) returns the number of hours elapsed from d1 to d2. For example, 
if d1 is 02/13/2100/00 and d2 is 02/14/2100/10, (d2 – d1) is equal to 34 hours. If d2 == d1, (d2 – d1) should be zero. 
If d2 < d1, (d2 – d1) should return –(d1 – d2) and therefore be negative


Suppose you want to calculate (d2-d1), the number of hours between dates d1 and d2. It may be simpler to calculate
n1: number of hours elapsed from 01/01/0001/00 to date d1.
n2: number of hours elapsed from 01/01/0001/00 to date d2.
then subtract n2 – n1 = d2 – d1.
For simplicity, you may assume:
• there is no leap year, and all the years are 365 days
• The dates are all greater than 01/01/0001/00.
Hint: To calculate the number of hours elapsed from 01/01/0001/00 to date d = mm/dd/yyyy/hh, you can calculate from these components: yyyy, mm, dd, and hh
n = (365 * (yyyy - 1) + f(mm) + dd)*24 + hh
where f(mm) is the number of days elapsed from Jan 1st of the same year to the first day of month mm. For example, f(01) = 0, because there are zero days from Jan 1st to the first day of January
f(02) = 31, because there are 31 days from Jan 1st to the first day of February
f(03) = 59, because there are 59 days from Jan 1st to the first day of March
f(04) = 90, because there are 90 days from Jan 1st to the first day of April, etc.
The suggestion is to implement the function f() as an array, where the month would be used as the index into the array.
*/
int Date::operator-(const Date & rhs) {
    //established array that set the number of days from the start of the given month
    int daysElapsed[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    
    //calculate for first operator
    //tried to follow formua set in comment
    int totalDays = ((year - 1) * 365) + daysElapsed[month] + (day - 1);
    int totalHours = totalDays * 24 + hour;
    
    //calculate for second operator
    int totalRhDays = ((rhs.year - 1) * 365) + daysElapsed[rhs.month] + (rhs.day - 1);
    int totalRhHours = (totalRhDays * 24) + rhs.hour;
    
    //adding test for extra credit leap year stuff
    //check if either of the years are leap years..
    int numLeaps = 0; //I forgot to initialize this, which was causing a ton of errors when adding it later
    // bool l1 = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    // bool l2 = ((rhs.year % 4 == 0 && rhs.year % 100 != 0) || (rhs.year % 400 == 0));
    // if (l1 || l2) {
    //     numLeaps = abs(year - rhs.year) / 4;
    // }
    for (int i = 1; i < year; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            numLeaps++;
        }
    }
    totalHours += (numLeaps * 24);
    numLeaps = 0;
    for (int i = 1; i < rhs.year; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            numLeaps++;
        }
    }
    totalRhHours += (numLeaps * 24);
    //totalHours += (abs(numLeaps) * 24);
    
    return totalHours - totalRhHours;
}
/*
• print(): Prints the date in the format ”Month dd, yyyy, hh:00”. For example, “March 12, 2103, 23:00”.
*/
void Date::print() {
    //set an array to give the corresponding month name to the given int var for the month
    //lmao, forgot to include "May" in this list ; - ;
    string nameOfMonth[13] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    cout << nameOfMonth[month] << " " << day << ", " << year << ", " << hour << ":00";
}
