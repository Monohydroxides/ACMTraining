#include <bits/stdc++.h>
using namespace std;

int n, m;
long long pre[100010];

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }
    return 0;
}