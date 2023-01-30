#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void work () {
	ll l, r;
	cin >> l >> r;
	if (l & 1 && r & 1) {
		cout << (r - l) / 2 + 1 << '\n';
	} else if (!(l & 1) && !(r & 1)) {
		cout << (r - l) / 2 << '\n';
	} else {
		cout << (r - l + 1) / 2 << '\n';
	}
}

int main () {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		work();
	}
	return 0;
}