#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    string str;
    cin >> str;
    str = " " + str;
    int l = 1;
    int cnt = 0;
    while (l <= n) {
        int r = l;
        if (r < n && str[l] == str[l + 1]) {
            r = l + 1;
        }
        if (cnt) {
            if (l == n || (l < n && str[l] != str[l + 1])) {
                cout << "NO\n";
                return;
            } else {
                l = l + 2;
            }
        } else {
            l += 1;
        }
        cnt ^= 1;
    }
    cout << "YES\n";
    return;
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}