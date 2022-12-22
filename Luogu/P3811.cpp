#include <bits/stdc++.h>
using namespace std;

int inv[3000010];

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    inv[1] = 1;
    cout << 1 << '\n';
    for(int i = 2; i <= n; ++i) {
        inv[i] = (p - (long long) (p / i) * inv[p % i] % p) % p;
        cout << inv[i] << '\n';
    }
    return 0;
}