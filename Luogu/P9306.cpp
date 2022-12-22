#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 10;

namespace Trie {
	int cnt[N], idx;
	int son[N][75];
	void init () {
		for (int i = 0; i <= idx; ++i) {
			for (int j = 0; j <= 63; ++j) {
				son[i][j] = 0;
			}
		}
		for (int i = 0; i <= idx; ++i) {
			cnt[i] = 0;
		}
		idx = 0;
	}
	int getIdx (char chr) {
		if (chr >= 'a' && chr <= 'z') {
			return chr - 'a';
		} else if (chr >= 'A' && chr <= 'Z') {
			return chr - 'A' + 26;
		} else {
			return chr - '0' + 52;
		}
	}
	void insert (string str) {
		int p = 0;
		for (int i = 0; str[i]; ++i) {
			int chr = getIdx(str[i]);
			if (!son[p][chr]) {
				son[p][chr] = ++idx;
			}
			p = son[p][chr];
			cnt[p]++;
		}
	}
	int query (string str) {
		int p = 0;
		for (int i = 0; str[i]; ++i) {
			int chr = getIdx(str[i]);
			if (!son[p][chr]) {
				return 0;
			}
			p = son[p][chr];
		}
		return cnt[p];
	}
};

void work () {
	int n, q;
	cin >> n >> q;
	Trie::init();
	string str;
	for (int i = 1; i <= n; ++i) {
		cin >> str;
		Trie::insert(str);
	}
	for (int i = 1; i <= q; ++i) {
		cin >> str;
		cout << Trie::query(str) << endl;
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