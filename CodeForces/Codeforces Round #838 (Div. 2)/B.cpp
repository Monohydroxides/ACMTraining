#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[100010];

bool cmp (pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void work () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector< pair<int, int> > res;
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; ++i) {
        if (a[i].first % a[i - 1].first) {
            res.push_back({a[i].second, a[i - 1].first - a[i].first % a[i - 1].first});
            a[i].first += a[i - 1].first - a[i].first % a[i - 1].first;
        }
    }
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].first << " " << res[i].second << '\n';
    }
    return;
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