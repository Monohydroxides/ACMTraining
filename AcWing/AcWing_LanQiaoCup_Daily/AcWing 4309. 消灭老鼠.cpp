#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9 + 1;

unordered_map<double, int> mp;

int main () {
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if (x == x0) {
            mp[inf]++;
            // cout << "k:" << inf << "\n";
        } else {
            mp[(double) (y - y0) / (x - x0)]++;
            // cout << "k:" << (y - y0) / (x - x0) << "\n";
        }
    }
    cout << mp.size() << "\n";
    return 0;
}