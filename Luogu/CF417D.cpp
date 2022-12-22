#include <bits/stdc++.h>
using namespace std;

const unsigned long long inf = 1e19;

int n, m, b;
struct friends {
	unsigned long long x, k, st;
	bool operator< (const struct friends& Fri) const {
		return k < Fri.k;
	}
} fri[110];
unsigned long long dp[1 << 20];
unsigned long long res = inf;

int main () {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> b;
	unsigned long long xi, ki, mi, pi;
	for (int i = 1; i <= n; ++i) {
		cin >> xi >> ki >> mi;
		unsigned long long st = 0;
		for (int j = 1; j <= mi; ++j) {
			cin >> pi;
			st |= 1 << (pi - 1);
		}
		fri[i] = {xi, ki, st};
	}

	sort(fri + 1, fri + 1 + n);

	for (int i = 1; i < (1 << 20); ++i) {
		dp[i] = inf;
	}
	dp[0] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int state = 0; state < (1 << m); ++state) {
			if (dp[state] == inf) {
				continue;
			}
			dp[state | fri[i].st] = min(dp[state | fri[i].st], dp[state] + fri[i].x);
		}
		if (dp[(1 << m) - 1] != inf) {
			res = min(res, dp[(1 << m) - 1] + b * fri[i].k);
		}
	}

	if (res == inf) {
		cout << -1 << '\n';
	} else {
		cout << res << '\n';
	}
	return 0;
}