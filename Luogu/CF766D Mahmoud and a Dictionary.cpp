#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, q;
int fa[2 * N];

map <string, int> mp;

int find (int x) {
	if (x == fa[x]) {
		return fa[x];
	}
	return fa[x] = find(fa[x]);
}

int main () {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
		fa[i + n] = i + n;
	}
	string str1, str2;
	for (int i = 1; i <= n; ++i) {
		cin >> str1;
		mp[str1] = i;
	}
	int rel;
	for (int i = 1; i <= m; ++i) {
		cin >> rel >> str1 >> str2;
		int id1 = mp[str1], id2 = mp[str2];
		if (rel == 1) {
			int p1 = find(id1), p2 = find(id2 + n);
			if (p1 == p2) {
				cout << "NO" << '\n';
				continue;
			}
			cout << "YES" << '\n';
			p1 = find(id1), p2 = find(id2);
			if (p1 != p2) {
				fa[p2] = p1;
			}
			p1 = find(id1 + n), p2 = find(id2 + n);
			if (p1 != p2) {
				fa[p2] = p1;
			}
		} else {
			int p1 = find(id1), p2 = find(id2);
			if (p1 == p2) {
				cout << "NO" << '\n';
				continue;
			}
			cout << "YES" << '\n';
			p1 = find(id1), p2 = find(id2 + n);
			if (p1 != p2) {
				fa[p2] = p1;
			}
			p1 = find(id1 + n), p2 = find(id2);
			if (p1 != p2) {
				fa[p2] = p1;
			}
		}
	}
	for (int i = 1; i <= q; ++i) {
		cin >> str1 >> str2;
		int id1 = mp[str1], id2 = mp[str2];
		int p1 = find(id1), p2 = find(id2);
		if (p1 == p2) {
			cout << 1 << '\n';
		} else {
			p1 = find(id1), p2 = find(id2 + n);
			if (p1 == p2) {
				cout << 2 << '\n';
			} else {
				cout << 3 << '\n';
			}
		}
	}
	return 0;
}