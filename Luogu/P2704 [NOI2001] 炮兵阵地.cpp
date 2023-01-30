#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100];
int dp[1 << 10][1 << 10][3];
int sum[1 << 10];

int getStateNum (int state) {
    int res = 0;
    while (state) {
        if (state & 1) {
            res++;
        }
        state >>= 1;
    }
    return res;
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < m; ++j) {
            if (str[j] == 'H') {
                a[i] |= 1 << j;
            }
        }
    }
    for (int state = 0; state < (1 << m); ++state) {
        sum[state] = getStateNum(state);
    }
    for (int state = 0; state < (1 << m); ++state) {
        if (!((state & a[0]) || (state & (state << 1)) || (state & (state << 2)))) {
            dp[0][state][0] = sum[state];
        }
    }
    for(int las = 0; las < (1 << m); ++las) {
        for(int state = 0; state < (1 << m); ++state) {
            if(!((las & state) || (las & a[0]) || (state & a[1]) || (las & (las << 1))
            || (las & (las << 2)) || (state & (state << 1)) || (state & (state << 2)))) {
                dp[las][state][1] = sum[state] + sum[las];
            }
        }
    }
    for (int i = 2; i < n; ++i) {
        for (int las = 0; las < (1 << m); ++las) {
            if ((las & a[i - 1]) || (las & (las << 1)) || (las & (las << 2))) {
                continue;
            }
            for (int state = 0; state < (1 << m); ++state) {
                if ((state & a[i]) || (las & state) || (state & (state << 1)) || (state & (state << 2))) {
                    continue;
                }
                for (int laslas = 0; laslas < (1 << m); ++laslas) {
					if ((laslas & las) || (laslas & state) || (laslas & a[i - 2])
                    || (laslas & (laslas << 1)) || (laslas & (laslas << 2))) {
                        continue;
                    }
					dp[las][state][i % 3] = max(dp[las][state][i % 3], dp[laslas][las][(i - 1) % 3] + sum[state]);
				}
            }
        }
    }
    int res = 0;
    for(int las = 0; las < (1 << m); ++las) {
        for(int state = 0; state < (1 << m); ++state) {
			res = max(res, dp[las][state][(n - 1) % 3]);
        }
    }
	cout << res << endl;
    return 0;
}