#include <bits/stdc++.h>
using namespace std;

int n;
int res;
map<int, int> mp;

void work (int lft, int ans) {
    if (!lft) {
        if (!mp.count(ans)) res++, mp[ans] = 1;
        return;
    }
    for (int i = 1; i <= lft; i++) {
        work(lft - i, ans + i * (n - i));
    }
}

int main () {
    cin >> n;
    work(n, 0);
    cout << res << '\n';
    return 0;
}