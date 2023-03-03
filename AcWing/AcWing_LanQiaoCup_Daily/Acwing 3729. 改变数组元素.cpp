#include <bits/stdc++.h>
using namespace std;

int T;
int a[200010];

int main () {
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (x) {
				if (i >= x) a[i - x + 1]++;
				else a[1]++;
				a[i + 1]--;
			}
		}
		for (int i = 1; i <= n; i++) {
			a[i] += a[i - 1];
			cout << (a[i] > 0) << " ";
		} 
		cout << "\n";
	}
	return 0;
}
