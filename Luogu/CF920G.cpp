#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e7;

int primes[N + 10], cnt;
bool st[N + 10];
int mu[N + 10];

void init () {
    mu[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (!st[i]) {
            primes[cnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; primes[j] * i <= N; ++j) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                break;
            }
            mu[primes[j] * i] = -mu[i];
        }
    }
}

int check (int x, int p) {
    int res = 0;
    for (int i = 1; i * i <= p; ++i) {
	    if (p % i)  continue;
		res += mu[i] * (x / i);
		if (p / i != i) res += mu[p / i] * (x / (p / i));
	}
    return res;
}

void work () {
    int x, p, k;
    cin >> x >> p >> k;
    int pre = check(x, p);
    int l = x + 1, r = 1e7;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid, p) - pre >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    init();
    while (T--) {
        work();
    }
    return 0;
}