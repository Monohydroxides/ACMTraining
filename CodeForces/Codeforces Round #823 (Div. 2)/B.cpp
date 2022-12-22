#include <bits/stdc++.h>
using namespace std;

int n, loc;
pair<int, int> xt[200010];
long double eps = 1e-7;

bool check (long double x0) {
    for (int i = 1; i <= n; ++i) {
        if (fabs(fabs(xt[i].first - x0) - fabs(xt[loc].first - x0)) > eps) {
            return false;
        }
    }
    return true;
}

void work () {
    cin >> n;
    loc = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> xt[i].first;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> xt[i].second;
        if (xt[i].second > xt[loc].second) {
            loc = i;
        }
    }
    if (n == 1) {
        cout << xt[1].first << '\n';
        return;
    }
    long double l = 0, r = 1e8;
    while (fabs(r - l) > eps) {
        long double mid = (r + l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l << endl;
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}