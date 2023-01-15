#include <bits/stdc++.h>
using namespace std;

const int N = 100010, mod = 1e9 + 7;

int n;
int ma, mb;
int a[N], b[N];

int main () {
    cin >> n >> ma;
    for (int i = 1; i <= ma; i++) cin >> a[i];
    cin >> mb;
    for (int i = 1; i <= mb; i++) cin >> b[i];
    reverse(a + 1, a + 1 + ma);
    reverse(b + 1, b + 1 + mb);
    long long K = 1;
    long long res = 0;
    for (int i = 1; i <= ma; i++) {
        int k = max({a[i] + 1, b[i] + 1, 2});
        res = (res + (a[i] - b[i]) * K) % mod;
        K = (K * k) % mod;
    }
    cout << res << '\n';
    return 0;
}
