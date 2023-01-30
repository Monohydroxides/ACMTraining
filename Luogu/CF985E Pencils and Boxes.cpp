#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n, k, d;
int arr[N];
int f[N];

int main () {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + 1 + n);
	f[0] = 1;
	int ed = 1;
	for (int i = 0; i <= n; ++i) {
		if (f[i]) {
			ed = max(ed, i + k);
			while (ed <= n && arr[ed] - arr[i + 1] <= d) {
				f[ed] = 1;
				ed++;
			}
		}
	}
	cout << endl;
	if (f[n]) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
	return 0;
}