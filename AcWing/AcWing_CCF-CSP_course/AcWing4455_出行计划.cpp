#include <bits/stdc++.h>
using namespace std;

int n, m, k;
map<int, int> mp;

int main () {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a - k + 1 - b]++;
        mp[a - k + 1]--;
    }
    for(int i = -3e5 + 10; i < 3e5 + 10; i++){
        mp[i] += mp[i - 1];
    }
    while (m--) {
        int x;
        cin >> x;
        cout << mp[x] << '\n';
    }
    return 0;
}
