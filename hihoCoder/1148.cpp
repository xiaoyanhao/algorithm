#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    return false;
}

int hasLeapYear(int month, int day, int year) {
    int count = year / 400 + year / 4 - year / 100;
    if (isLeapYear(year)) {
        if (month < 2 || (month == 2 && day <= 29)) {
            count--;
        }
    }
    return count;
}

int main() {
    string month[12] = {
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };
    map<string, int> months;
    for (int i = 0; i < 12; i++) {
        months[month[i]] = i + 1;
    }
    
    int T, y, d, count;
    char m[10];
    cin >> T;
    
    for (int i = 1; i <= T; i++) {
        scanf("%s %d, %d", m, &d, &y);
        count = hasLeapYear(months[m], d, y);
        scanf("%s %d, %d", m, &d, &y);
        count = hasLeapYear(months[m], d + 1, y) - count;
        cout << "Case #" << i << ": " << count << endl;
    }
    return 0;
}

