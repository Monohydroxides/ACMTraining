#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 10;

int n;
int arr[N], res[N];
stack< pair<int, int> > st;

int main () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (!st.size()) {
			st.push({arr[i], i});
		} else {
			while (st.size() && st.top().first < arr[i]) {
				res[st.top().second] = i;
				st.pop();
			}
			st.push({arr[i], i});
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}