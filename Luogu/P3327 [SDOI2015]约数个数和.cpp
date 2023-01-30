#include <bits/stdc++.h>
using namespace std;

bool st[50010];
int primes[50010], cnt;
int mu[50010];
long long g[50010];

void init () {
	int n = 50000;
	mu[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!st[i]) {
			primes[cnt++] = i;
			mu[i] = -1;
		}
		for (int j = 0; primes[j] * i <= n; ++j) {
			st[primes[j] * i] = 1;
			if (i % primes[j] == 0) {
				break;
			}
			mu[primes[j] * i] = -mu[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		mu[i] += mu[i - 1];
	}

	for (int i = 1; i <= n; ++i) {
		long long res = 0;
		for (int l = 1, r; l <= i; l = r + 1) {
			r = i / (i / l);
			res += (long long) (r - l + 1) * (i / l);
		}
		g[i] = res;
	}
}

long long calc (int x) {
	long long res = 0;
	for (int l = 1, r; l <= x; l = r + 1) {
		r = x / (x / l);
		res += (long long) (r - l + 1) * (x / l);
	}
	return res;
}

void work () {
	long long res = 0;
	int n, m;
	cin >> n >> m;
	for (int l = 1, r; l <= min(n, m); l = r + 1) {
		r = min(n / (n / l), m / (m / l));
		res += (long long) (mu[r] - mu[l - 1]) * g[n / l] * g[m / l];
	}
	cout << res << endl;
}

int main () {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	init();
	int T;
	cin >> T;
	while (T--) {
		work();
	}
	return 0;
}