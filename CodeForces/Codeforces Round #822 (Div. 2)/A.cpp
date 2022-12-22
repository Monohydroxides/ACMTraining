#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int res = 0x3f3f3f3f;
    for (int i = 1; i < a.size() - 1; ++i) {
        res = min(res, a[i + 1] - a[i - 1]);
    }
    cout << res << '\n';
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