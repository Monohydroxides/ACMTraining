#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

map< pair< int, int >, long double > mp;

long double dp (int a, int b) {
    if (mp.count({a, b})) {
		return mp[{a, b}];
	}
	if (a < 0 || b < 0) {
		return mp[{a, b}] = (ld) 0.0;
	}
	if (!b) {
		if (a) {
			return mp[{a, b}] = (ld) 1.0;
		} else {
			return mp[{a, b}] = (ld) 0.0;
		}
	}
	if (!a) {
		return (ld) 0.0;
	}
	ld res = ((ld) a / (ld) (a + b));
    if (a + b - 2 > 0) {
        res += (
            ((ld) b / (ld) (a + b)) * ((ld) (b - 1) / (ld) (a + b - 1)) *
            ((ld) a / (ld) (a + b - 2) * dp(a - 1, b - 2) +
                ((ld) (b - 2) / (ld) (a + b - 2) * dp(a, b - 3))
            )
        );
    }
    return mp[{a, b}] = res;
}

int main () {
	int a, b;
	cin >> a >> b;
    cout << fixed << setprecision(9) << dp(a, b) << endl;
	return 0;
}