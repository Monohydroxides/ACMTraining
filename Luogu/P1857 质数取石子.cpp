#include <bits/stdc++.h>
using namespace std;

bool st[20010];
vector<int> primes;
pair<int, int> f[20010];

void init () {
    int n = 20000;
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            primes.emplace_back(i);
        }
        for (int j = 0; primes[j] * i <= n; ++j) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        f[i].second = 0x3f3f3f3f;
    }
    f[0] = {-1, 0};
    f[1] = {-1, 0};
    for (int i = 0; i < primes.size(); ++i) {
        f[primes[i]] = {1, 1}; 
    }
    for (int i = 1; i <= n; ++i) {
        if (f[i].first != 0) {
            continue;
        }
        int l = 0, r = primes.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (primes[mid] < i) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        int flg = 0;
        for (int j = l; j >= 0; --j) {
            if (f[i - primes[j]].first == -1) {
                f[i].first = 1;
                f[i].second = min(f[i].second, f[i - primes[j]].second + 1);
                flg = 1;
            }
        }
        if (flg) {
            continue;
        }
        f[i] = {-1, 0};
        for (int j = l; j >= 0; --j) {
            f[i].second = max(f[i].second, f[i - primes[j]].second + 1);
        }
    }
}

void work () {
    int n;
    cin >> n;
    if (f[n].first == 1) {
        cout << f[n].second << endl;
    } else {
        cout << -1 << endl;
    }
}

int main () {
    init();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}