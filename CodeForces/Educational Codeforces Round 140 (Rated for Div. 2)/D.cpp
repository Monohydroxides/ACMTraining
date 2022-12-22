#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    string str;
    cin >> str;
    str = " " + str;
    int l = 1, r = pow(2, n);
    int cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= n; ++i) {
        if (str[i] == '1') {
            l += pow(2, cnt1);
            cnt1++;
        } else {
            r -= pow(2, cnt0);
            cnt0++;
        }
    }
    for (int i = l; i <= r; ++i) {
        cout << i << " ";
    }
    cout << '\n';
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T = 1;
    while (T--) {
        work();
    }
    return 0;
}