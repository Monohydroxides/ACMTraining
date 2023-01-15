#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

long long n, m;
long long a[N], b[N];

bool check (int v) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= v) {
            cnt += (a[i] - v) / b[i] + 1;
        }
    }
    return cnt >= m;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    
    int l = 0, r = 1e6;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    
    long long res = 0;
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < r) continue;
        long long cur = (a[i] - r) / b[i] + 1;
        long long ed = a[i] - (cur - 1) * b[i];
        res += (long long) (a[i] + ed) * cur / 2;
        cnt += cur;
    }
    res -= (long long) (cnt - m) * r;
    cout << res << '\n';
    return 0;
}