#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> loc;
vector<pair<int, int>> opt, que;
int a[300010], s[300010];
int find(int x) {
    int l = 0, r = loc.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (loc[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l + 1;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x, c;
        cin >> x >> c;
        opt.push_back({x, c});
        loc.push_back(x);
    }
    for (int j = 1; j <= m; ++j) {
        int l, r;
        cin >> l >> r;
        loc.push_back(l), loc.push_back(r);
        que.push_back({l, r});
    }
    sort(loc.begin(), loc.end());
    loc.erase(unique(loc.begin(), loc.end()), loc.end());
    for (int i = 0; i < opt.size(); ++i) {
        int x = find(opt[i].first);
        a[x] += opt[i].second;
    }
    for (int i = 1; i <= loc.size(); ++i) {
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 0; i < que.size(); ++i) {
        printf("%d\n", s[find(que[i].second)] - s[find(que[i].first) - 1]);
    }
    return 0;
}

