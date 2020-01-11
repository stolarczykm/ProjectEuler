// https://www.hackerrank.com/contests/projecteuler/challenges/euler019/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


struct Date {
    int year;
    int month;
    int day;
    int weekday;
    Date(int year_=0, int month_=0, int day_=0, int weekday_=5):
        year(year_), month(month_), day(day_), weekday(weekday_) {};


    bool is_leap_year() {
        return year % 4 == 0 && (!(year % 100 == 0) || year % 400 == 0);
    }
    
    void next_month() {
        weekday = (weekday + days_in_month[month] + (int)(is_leap_year() && month == 1)) % 7;
        year += (month == 11) ? 1 : 0;
        month = (month + 1) % 12;
    }

    friend bool operator==(const Date& lhs, const Date& other) {
        return lhs.year == other.year && lhs.month == other.month && lhs.day == other.day;
    }

    friend bool operator<(const Date& lhs, const Date& other) {
        return (
            lhs.year < other.year
            || (lhs.year == other.year && lhs.month < other.month)
            || (lhs.year == other.year && lhs.month == other.month && lhs.day < other.day)
        );
    }
};


template <class T>
int count_lower(const vector<T>& x, T element, bool strict=true, int left=0, int right=-1) {
    if (right == -1) 
        right = x.size();
    if (right - left < 1) 
        return left;

    int middle = left + (right - left) / 2;

    if (x[middle] == element) {
        return middle + int(!strict);
    }

    if (element < x[middle]) {
        return count_lower(x, element, strict, left, middle);
    }

    return count_lower(x, element, strict, middle + 1, right);
}

int main() {
    // vector<int> x = {2, 4, 6, 8};
    // for (int i = 0; i < 10; ++i) {
    //     cout << i << " " << count_lower(x, i) << " " << count_lower(x, i, 0, -1, false)<< endl;
    // }

    vector<Date> sundays = {};

    Date date = Date(0, 0, 0, 5);
    while (date.year < 2800) 
    {   
        if (date.weekday == 6) {
            sundays.push_back(Date(date.year, date.month, date.day, date.weekday));
        }
        date.next_month();
    }

    int t0;
    cin >> t0;

    for (int i = 0; i < t0; ++i) {
        long y1, m1, d1, y2, m2, d2;
        cin >> y1; cin >> m1; cin >> d1;
        cin >> y2; cin >> m2; cin >> d2;
        auto date1 = Date(y1 % 2800, m1-1, d1-1, -1);
        auto date2 = Date(y2 % 2800, m2-1, d2-1, -1);
        auto n2 = count_lower(sundays, date2, false);
        auto n1 = count_lower(sundays, date1, true);

        for (int i = n1-1; i <= n2; ++i) {
            cout << sundays[i].year << " " << sundays[i].month + 1 << " " << sundays[i].day + 1 << endl;
        }

        cout << n2 - n1 + sundays.size() * int(n2 - n1 < 0) << endl;
    }

    return 0;
}



