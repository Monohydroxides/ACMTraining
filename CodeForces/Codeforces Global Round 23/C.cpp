#include <bits/stdc++.h>
using namespace std;

void work () {
    int n;
    cin >> n;
    vector<int> a(n + 1), res(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        res[a[i]] = i + 1;
    }
    for (int i = 1; i <= n; ++i) {
        cout << min(res[i], n) << " ";
    }
    cout << '\n';
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