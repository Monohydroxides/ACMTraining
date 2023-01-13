#include <bits/stdc++.h>
using namespace std;

int l, r;

int mon[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check (int x) {
    int year = x / 10000, month = (x / 100) % 100, day = x % 100;
    if (year < l / 10000 || year > r / 10000) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    if (month != 2 && day > mon[month]) return false;
    if (month == 2) {
        if ((year % 100 == 0 && year % 400 == 0) || (year % 4 == 0)) {
            if (day > 29) return false;
        } else if (day > 28) return false;
    }
    if (year < (l / 10000) || year > (r / 10000)) return false;
    if (year == (l / 10000)) {
        int lmonth = (l / 100) % 100;
        if (month < lmonth) return false;
        else if (month == lmonth) {
            if (day < l % 100) return false;
        }
    }
    if (year == (r / 10000)) {
        int rmonth = (r / 100) % 100;
        if (month > rmonth) return false;
        else if (month == rmonth) {
            if (day > r % 100) return false;
        }
    }
    return true;
}

int main () {
    cin >> l >> r;
    int res = 0;
    for (int i = 1000; i <= 9999; i++) {
        int x = i, tmp = x;
        while (tmp) {
            x = x * 10 + tmp % 10;
            tmp /= 10;
        }
        if (check(x)) res++;
    }
    cout << res << '\n';
    return 0;
}

