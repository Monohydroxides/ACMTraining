#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    if (cnt.size() == 1) {
        cout << "NO\n";
        return 0;
    }
    int flg = 1;
    for (auto [k, v]: cnt) {
        if (flg) {
            flg = 0;
        } else {
            cout << k << '\n';
            return 0;
        }
    }
    return 0;
}