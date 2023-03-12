#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<int, int> cnt;

int main () {
    cin >> n;
    for (int i = 0; i * i <= n; i++) {
        for (int j = i; i * i + j * j <= n; j++) {
            if (!cnt.count(i * i + j * j)) {
                cnt[i * i + j * j] = i;
            }
        }
    }
    for (int i = 0; i * i <= n; i++) {
        for (int j = i; i * i + j * j <= n; j++) {
            int ret = n - i * i - j * j;
            if (cnt.count(ret)) {
                cout << i << " " << j << " " << cnt[ret] << " " << sqrtl(ret - cnt[ret] * cnt[ret]) << "\n";
                return 0;
            }
        }
    }
    return 0;
}