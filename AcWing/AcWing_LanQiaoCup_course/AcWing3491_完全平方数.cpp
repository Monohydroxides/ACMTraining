#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int primes[N + 5], cnt;
bool st[N + 5];

long long n;

void init () {
    for (int i = 2;  i <= N; i++) {
        if (!st[i]) {
            primes[++cnt] = i;
        }
        for (int j = 1; primes[j] * i <= N; j++) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

vector<pair<long long, int>> get (long long x) {
    vector<pair<long long, int>> res;
    for (int j = 1; j <= cnt; j++) {
        if (x % primes[j] == 0) {
            int cnt = 0;
            while (x % primes[j] == 0) {
                x /= primes[j];
                cnt++;
            }
            res.push_back({primes[j], cnt});
        }
    }
    if (x > 1) res.push_back({x, 1});
    return res;
}

int main () {
    cin >> n;
    init();
    auto fac = get(n);
    long long ans = 1;
    for (auto it : fac) {
        if (it.second & 1) {
            ans *= it.first;
        }
    }   
    cout << ans << '\n';
    return 0;
}