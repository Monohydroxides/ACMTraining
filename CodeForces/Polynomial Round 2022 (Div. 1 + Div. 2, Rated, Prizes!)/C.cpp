#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    string str;
    cin >> str;
    str = " " + str;
    int cur = -1;
    int cnt = 0;
    for (int x = 1; x <= n - 1; ++x) {
        if (cur == -1 || (cur == 1 && str[x] == '0') || (cur == 0 && str[x] == '1')) {
            cur = str[x] - '0';
            cnt = 1;
        } else {
            cnt++;
        }
        cout << x + 1 - cnt << ' ';
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