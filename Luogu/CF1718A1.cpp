#include <bits/stdc++.h>
using namespace std;

int a[5010];
map<int, int> mp;

void work () {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    mp.clear();
    int cur = 0;
    mp[0] = 1; 
    for (int i = 1; i <= n; ++i) {
        cur ^= a[i];
        if (mp[cur]) {
            res++;
            mp.clear();
        }
        mp[cur] = 1;
    } 
    cout << n - res << '\n';
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
}