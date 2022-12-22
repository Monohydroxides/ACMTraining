#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

void work () {
    string str, tmp;
    cin >> str;
    int n = str.size();
    int flg = 0, loc = 0;
    int cnt[10];
    for (int i = 0; i <= 9; ++i) {
        flg = 0;
        loc = -1;
        for (int j = 0; j <= 9; ++j) {
            cnt[j] = 0;
        }
        tmp = "";

        for (int j = n - 1; j >= 0; --j) {
            if (str[j] - '0' == i) {
                flg = 1;
                loc = j;
                break;
            }
        }
        if (!flg) {
            continue;
        }
        for (int j = 0; j <= loc; ++j) {
            if (str[j] - '0' > i) {
                cnt[str[j] - '0']++;
            } else {
                tmp = tmp + str[j];
            }
        }
        for (int j = i + 1; j < 10; ++j) {
            tmp.append(cnt[j], (char) (min(j + 1, 9) + '0'));
        }
        for (int j = loc + 1; j < n; ++j) {
            tmp = tmp + str[j];
        }
        str = tmp;
    }
    cout << str << '\n';
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