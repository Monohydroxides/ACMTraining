#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int primes[N + 1], cnt;
bool st[N + 1];

int res = 0;
int a0, a1, b0, b1;

void init () {
    for (int i = 2; i <= N; i++) {
        if (!st[i]) {
            primes[++cnt] = i;
        }
        for (int j = 1; primes[j] * i <= N; j++) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

vector<pair<int, int>> get (int x) {
    vector<pair<int, int>> ans;
    for (int i = 1; i <= cnt; i++) {
        if (x == 1) break;
        if (x % primes[i] == 0) {
            int cnt = 0;
            while (x % primes[i] == 0) {
                x /= primes[i];
                cnt++;
            }   
            ans.push_back({primes[i], cnt});
        }
    }
    if (x > 1) {
        ans.push_back({x, 1});
    }
    return ans;
}

void dfs (vector<pair<int, int>> & fac, int cur, int ans) {
    if (cur >= fac.size()) {
        if (__gcd(ans, a0) == a1 && ans / __gcd(b0, ans) * b0 == b1) {
            res++;
        }
        return;
    }
    dfs(fac, cur + 1, ans);
    for (int i = 1; i <= fac[cur].second; i++) {
        ans = ans * fac[cur].first;
        dfs(fac, cur + 1, ans);
    }
}

int main () {
    init();
    int T;
    cin >> T;
    while (T--) {
        cin >> a0 >> a1 >> b0 >> b1;
        res = 0;
        auto fac = get(b1);
        dfs(fac, 0, 1);
        cout << res << "\n";
    }
    return 0;
}