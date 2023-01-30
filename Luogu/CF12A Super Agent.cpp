#include <bits/stdc++.h>
using namespace std;
int main () {
    string str[4];
    for (int i = 1; i <= 3; i++) {
        cin >> str[i];
    }
    int flg = 1;
    for (int i = 0; i < 3; i++) {
        if (str[1][i] != str[3][3 - i - 1]) {
            flg = 0;
            break;
        }
    }
    if (str[2][0] != str[2][2]) {
        flg = 0;
    }
    if (flg) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}