#include <bits/stdc++.h>
using namespace std;

int n, m, sep;
int l, r;
int res;
int a[1000010], ans[1000010], cnt[1000010];

struct MoQuery {
    int id, l, r;
    bool operator<(MoQuery &a) const {
        if(l / sep != a.l / sep)    return l / sep < a.l / sep;
        return r < a.r;
    }
} qry[1000010];

void add(int x) {
    if(!cnt[x]) res++;
    cnt[x]++;
}

void del(int x) {
    cnt[x]--;
    if(!cnt[x]) res--;
}

int main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    cin >> m;
    sep = n / sqrt(m) + 1;
    for(int i = 1; i <= m; ++i) {
        cin >> qry[i].l >> qry[i].r;
        qry[i].id = i;
    }
    sort(qry + 1, qry + 1 + m);
    l = 1, r = 0;
    for(int i = 1; i <= m; ++i) {
        while(l > qry[i].l) add(a[--l]);
        while(r < qry[i].r) add(a[++r]);
        while(l < qry[i].l) del(a[l++]);
        while(r > qry[i].r) del(a[r--]);
        ans[qry[i].id] = res;
    }
    for(int i = 1; i <= m; ++i) cout << ans[i] << endl;
    return 0;
}
