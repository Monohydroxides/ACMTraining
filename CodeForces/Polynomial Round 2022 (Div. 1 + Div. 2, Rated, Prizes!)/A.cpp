#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    string str;
    cin >> str;
    str = " " + str;
    int cnt = str[1] == '1';
    for (int i = 2; i <= n; ++i) {
        if (str[i] == '1') {
            if (cnt > 0) {
                cout << '-';
                cnt--;
            } else {
                cout << '+';
                cnt++;
            }
        } else {
            cout << "+";
        }
    }
    cout << '\n';
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