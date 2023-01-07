#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> hashv;
const long long mod1=1000000007;
const long long mod2=1000000009;

hashv operator + (hashv a, hashv b) {
	int c1 = a.first + b.first;
    int c2 = a.second + b.second;
	if (c1 >= mod1) c1 -= mod1;
	if (c2 >= mod2) c2 -= mod2;
	return make_pair(c1, c2);
}

hashv operator - (hashv a, hashv b) {
	int c1 = a.first - b.first;
    int c2 = a.second - b.second;
	if (c1 < 0) c1 += mod1;
	if (c2 < 0) c2 += mod2;
	return make_pair(c1, c2);
}

hashv operator * (hashv a, hashv b) {
	return make_pair(1ll * a.first * b.first % mod1, 1ll * a.second * b.second % mod2);
}

const int N = 2010000;
int n;
hashv power[N], s[N], t[N];
string str;

int main() {
	cin >> n;
	cin >> str;
    str = " " + str;
	hashv base = make_pair(13331, 23333);
	power[0] = make_pair(1, 1);
	for (int i = 1; i <= 2 * n; i++) {
		power[i] = power[i - 1] * base;
        s[i] = s[i - 1] * base + make_pair(str[i], str[i]);
	}
    for (int i = 2 * n; i >= 1; i--) {
        t[i] = t[i + 1] * base + make_pair(str[i], str[i]);
    }
    for (int i = 1; i <= n; i++) {
        hashv s1 = s[i] * power[n - i] + (s[2 * n] - s[i + n] * power[n - i]);
        hashv s2 = t[i + 1] - t[i + n + 1] * power[n];
        if (s1 == s2) {
            for (int j = i + n; j >= i + 1; j--) {
                cout << str[j];
            }
            cout << '\n';
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
	return 0;
}
