#include <bits/stdc++.h>
using namespace std;

int a[200010];

void work () {
    int n;
    string str;
    cin >> n;
    cin >> str;
    str = " " + str;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int res = 0;
    int l = 1;
    while (l <= n) {
        if (str[l] != '1') {
            l++;
            continue;
        }
        vector<int> tmp;
        if (l > 1) {
            tmp.push_back(a[l - 1]);
        }
        int r = l;
        while (r <= n && str[r] == '1') {
            tmp.push_back(a[r]);
            r++;
        }
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        for (int cnt = 0; cnt < r - l; ++cnt) {
            res += tmp[cnt];
        }
        l = r;
    }
    cout << res << '\n';
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