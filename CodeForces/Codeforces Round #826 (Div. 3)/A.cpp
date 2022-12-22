#include <bits/stdc++.h>
using namespace std;

void work () {
    string str1, str2;
    cin >> str1 >> str2;
    if (str1[str1.size() - 1] != str2[str2.size() - 1]) {
        if (str1[str1.size() - 1] == 'S') {
            cout << '<' << '\n';
        } else if (str1[str1.size() - 1] == 'M') {
            if (str2[str2.size() - 1] == 'S') {
                cout << '>' << '\n';
            } else {
                cout << '<' << '\n';
            }
        } else {
            cout << '>' << '\n';
        }
    } else {
        if (str1[str1.size() - 1] == 'S') {
            if (str1.size() > str2.size()) {
                cout << '<' << '\n';
            } else if (str1.size() == str2.size()) {
                cout << '=' << '\n';
            } else {
                cout << '>' << '\n';
            }
        } else if(str1[str1.size() - 1] == 'L') {
            if (str1.size() > str2.size()) {
                cout << '>' << '\n';
            } else if (str1.size() == str2.size()) {
                cout << '=' << '\n';
            } else {
                cout << '<' << '\n';
            }
        } else {
            cout << '=' << '\n';
        }
    }
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}