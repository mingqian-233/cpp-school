
#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

int daysInMonth(int year, int month) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month - 1];
}

bool isValidDateFormat(const char* date) {
    int year = 0, month = 0, day = 0;
    if (sscanf(date, "%d/%d/%d", &year, &month, &day) != 3)
        return false;
    if (year < 1919 || month < 1 || month > 12 || day < 1 || day > daysInMonth(year, month))
        return false;
    return true;
}
int daysBetweenDates(char date1[], char date2[]) {
    int year1, month1, day1;
    int year2, month2, day2;

    if (!isValidDateFormat(date1) || sscanf(date1, "%d/%d/%d", &year1, &month1, &day1) != 3)
        return -1;  // Invalid date1 format
    if (!isValidDateFormat(date2) || sscanf(date2, "%d/%d/%d", &year2, &month2, &day2) != 3)
        return -1;  // Invalid date2 format

    cout << year1 << month1 << day1 << endl;
    cout << year2 << month2 << day2 << endl;

    int days = 0;

    for (int year = year1; year < year2; year++) {
        days += isLeapYear(year) ? 366 : 365;
    }

    for (int month = 1; month < month1; month++) {
        days -= daysInMonth(year1, month);
    }
    for (int month = 1; month < month2; month++) {
        days += daysInMonth(year2, month);
    }

    days += day2 - day1;

    return days;
}

int main() {
    char date1[] = "1919/10/10";
    char date2[12];
    int days;
    cout << "The first date is 1919/10/10." << '\n';
    cout << "Enter date2 in the format (yyyy/mm/dd):" << '\n';
    while (1) {
        cin >> date2;
        days = daysBetweenDates(date1, date2);
        if (days < 0)
            cout << "Invalid date format. Please make sure you enter date2 in the format (yyyy/mm/dd) and this day is NOT before 1919/10/10." << endl;
        else
            break;
    }
    cout << "Number of days between " << date1 << " and " << date2 << ": " << days << '\n';
    int remainders = days % 5;
    if (remainders <= 2)
        cout << "fishing" << '\n';
    else
        cout << "dry nets" << '\n';

    return 0;
}