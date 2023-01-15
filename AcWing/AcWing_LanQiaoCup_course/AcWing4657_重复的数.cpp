#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int blk;
int a[N];
struct Mo {
    int id;
    int l, r, k;
    bool operator< (const Mo& rhs) const {
        if (l / blk != rhs.l / blk)
            return l < rhs.l;
        if ((l / blk) & 1)
            return r < rhs.r;
        return r > rhs.r;
    }
} qry[N];

int ans[N];
int cnt[N];
int res[N];

void add (int x) {
    res[cnt[x]]--;
    cnt[x]++;
    res[cnt[x]]++;
}

void del (int x) {
    res[cnt[x]]--;
    cnt[x]--;
    res[cnt[x]]++;
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    blk = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        qry[i] = {i, l, r, k};
    }
    sort(qry + 1,  qry + 1 + m);
    int l = 0, r = 0;
    for (int i = 1; i <= m; i++) {
        while (l > qry[i].l) {
            add(a[--l]);
        }
        while (r < qry[i].r) {
            add(a[++r]);
        }
        while (l < qry[i].l) {
            del(a[l++]);
        }
        while (r > qry[i].r) {
            del(a[r--]);
        }
        ans[qry[i].id] = res[qry[i].k];
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}