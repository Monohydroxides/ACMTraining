#include <bits/stdc++.h>
using namespace std;

int n;
int a[200010];

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int cur = 2;
    map<int, int> mp;
    mp[1] = 0;
    for (int i = 1; i <= n; ++i) {
        mp[cur++] = mp[a[i]] + 1;
        mp[cur++] = mp[a[i]] + 1;
    }
    for (int i = 1; i <= 2 * n + 1; ++i) {
        cout << mp[i] << '\n';
    }
    return 0;
}