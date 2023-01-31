#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000010];
int cnt[1000010];
int tr[2][1000010];
vector<int> dis;

int find (int x) {
    int l = 0, r = dis.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (dis[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l + 1;
}

int lowbit (int x) { return x & (-x); }
void modify (int ty, int k, int x) {
    for (; k <= n; k += lowbit(k)) {
        tr[ty][k] += x;
    }
}
int query (int ty, int k) {
    int ans = 0;
    for (; k; k -= lowbit(k)) {
        ans += tr[ty][k];
    }
    return ans;
}

int main () {
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dis.push_back(a[i]);
        mx = max(mx, a[i]);
    }
    sort(dis.begin(), dis.end());
    dis.erase(unique(dis.begin(), dis.end()), dis.end());
    for (int i = n; i >= 1; i--) {
        cnt[i] = query(0, find(a[i]) - 1);
        modify(0, find(a[i]), 1);
    }
    long long ans = 0;
    mx = find(mx);
    for (int i = 1; i <= n; i++) {
        int pre = query(1, mx) - query(1, find(a[i]));
        ans += 1ll * pre * cnt[i];
        modify(1, find(a[i]), 1);
    }
    cout << ans << '\n';
    return 0;
}