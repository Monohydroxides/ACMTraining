#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m;

int arr[N];

int idx;
int root[N];
struct node {
	int l, r, val;
} tr[N << 6];

int newnode (int u) {
	int p = ++idx;
	tr[p] = tr[u];
	return p;
}

int build (int l, int r) {
	int p = ++idx;
	if (l == r) {
		tr[p].val = arr[l];
		return p;
	}
	int mid = l + r >> 1;
	tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
	return p;
}

int modify (int rot, int l, int r, int x, int k) {
	int p = newnode(rot);
	if (l == r && l == x) {
		tr[p].val = k;
	} else {
		int mid = l + r >> 1;
		if (x <= mid) {
			tr[p].l = modify(tr[p].l, l, mid, x, k);
		} else {
			tr[p].r = modify(tr[p].r, mid + 1, r, x, k);
		}
	}
	return p;
}

int query (int rot, int l, int r, int x) {
	if (l == r && l == x) {
		return tr[rot].val;
	}
	int mid = l + r >> 1;
	if (x <= mid) {
		return query(tr[rot].l, l, mid, x);
	} else {
		return query(tr[rot].r, mid + 1, r, x);
	}
}

void printTree (int rot) {
	cout << "rot: " << rot << endl;
	cout << tr[rot].l << " " << tr[rot].r << endl;
	if (!tr[rot].l || !tr[rot].r) {
		cout << tr[rot].val << endl;
	} else {
		printTree(tr[rot].l);
		printTree(tr[rot].r);
	}
}

int main () {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	root[0] = build(1, n);

	// printTree(root[0]);

	for (int i = 1; i <= m; ++i) {
		int ver, op, loc, value;
		cin >> ver >> op >> loc;
		if (op == 1) {
			cin >> value;
			root[i] = modify(root[ver], 1, n, loc, value);
		} else {
			root[i] = root[ver];
			cout << query(root[ver], 1, n, loc) << '\n';
		}
	}
	return 0;
}