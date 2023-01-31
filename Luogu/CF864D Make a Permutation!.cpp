#include <bits/stdc++.h>
using namespace std;

int n, ans;
int a[200010];
int cnt[200010];
bool tag[200010];

int main () {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
    queue<int> qu;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            qu.push(i);
        }
    }
	for (int i = 1; i <= n; i++) {
		int cur = qu.front();
		if (cnt[a[i]] > 1) {
			if (cur < a[i] || tag[a[i]] == 1) {
                ans += 1;
				cnt[a[i]]--;
				cnt[cur]++;
				a[i] = cur;
                qu.pop();
			} else {
				tag[a[i]]=1;
            }
        }
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
	return 0;
}
