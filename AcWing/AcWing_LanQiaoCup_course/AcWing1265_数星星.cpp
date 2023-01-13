#include <bits/stdc++.h>
using namespace std;

const int N = 32001;

int n;
int ans[20000];

vector<pair<int, int>> point;

int tr[33000];

int lowbit (int x) { return x & (-x); }

void modify (int x, int k) {
    for (; x <= N; x += lowbit(x)) tr[x] += k;
}

int query (int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += tr[x];
    return res;
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        x++, y++;
        point.push_back(make_pair(x, y));
    }
    sort(point.begin(), point.end());
    for (int i = 0; i < point.size(); i++) {
        ans[query(point[i].second)]++;
        modify(point[i].second, 1);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}