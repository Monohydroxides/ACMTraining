#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int N = 1e6 + 10;

int arr[N];
int res[2][N];

int main () {
	int n, k;
	cin >> n >> k;
	deque<pii> pq, pqg;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		while (!pq.empty() && arr[i] >= pq.back().second) {
			pq.pop_back();
		}
		while (!pqg.empty() && arr[i] <= pqg.back().second) {
			pqg.pop_back();
		}
		pq.push_back({i, arr[i]});
		pqg.push_back({i, arr[i]});
		while (i - k >= pq.front().first) {
			pq.pop_front();
		}
		while (i - k >= pqg.front().first) {
			pqg.pop_front();
		}
		if (i >= k) {
			res[0][i] = pq.front().second;
			res[1][i] = pqg.front().second;
		}
	}
	for (int i = k; i <= n; ++i) {
		cout << res[1][i] << " ";
	}
	cout << endl;
	for (int i = k; i <= n; ++i) {
		cout << res[0][i] << " ";
	}
	cout << endl;
	return 0;
}