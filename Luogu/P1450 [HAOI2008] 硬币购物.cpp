#include <bits/stdc++.h>
using namespace std;

int n, s;
int c[5], d[5];
long long dp[100010];

int main () {
	for (int i = 1; i <= 4; ++i) {
		cin >> c[i];
	}
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= 4; ++i) {
		for (int j = c[i]; j <= 100000; ++j) {
			dp[j] += dp[j - c[i]];
		}
	}
	while (n--) {
		for (int j = 1; j <= 4; ++j) {
			cin >> d[j];
		}
		cin >> s;
		long long res = dp[s];
		for (int state = 1; state <= 15; ++state) {
			int cur = s;
			int k = 0;
			for (int tmp = state, j = 1; tmp > 0; tmp >>= 1, ++j) {
				if (tmp & 1) {
					k ^= 1;
					cur -= (d[j] + 1) * c[j];
				}
			}
			if (cur >= 0) {
				if (k & 1) {
					res -= dp[cur];
				} else {
					res += dp[cur];
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}