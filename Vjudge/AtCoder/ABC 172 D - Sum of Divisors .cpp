#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = n / i;
        res += 1ll * i * ((long long) (l + r) * r / 2);
    }
    cout << res << '\n';
    return 0;
}