#include <bits/stdc++.h>
using namespace std;

long long n, q, res;
long long a[100010];
map<long long, long long> cnt;

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res += a[i];
        cnt[a[i]]++;
    }
    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;
        res = res - l * cnt[l] + r * cnt[l];
        cout << res << '\n';
        cnt[r] += cnt[l];
        cnt.erase(l);
    }
    return 0;
}