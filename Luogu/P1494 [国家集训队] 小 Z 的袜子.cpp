#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

int n, m;
int blk;
int a[N];
struct Mo {
    int id, l, r;
    bool operator< (const Mo& rhs) const {
        if (l / blk != rhs.l / blk) {
            return l < rhs.l;
        }
        if ((l / blk) & 1) {
            return r < rhs.r;
        }
        return r > rhs.r;
    }
} qry[N];
pair<long long, long long> ans[N];

long long res;
int cnt[N];

void add (int x) {
    res -= (1ll * cnt[x] * (cnt[x] - 1) / 2);
    cnt[x]++;
    res += (1ll * cnt[x] * (cnt[x] - 1) / 2); 
}

void del (int x) {
    res -= (1ll * cnt[x] * (cnt[x] - 1) / 2);
    cnt[x]--;
    res += (1ll * cnt[x] * (cnt[x] - 1) / 2); 
}

long long gcd (long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main () {
    scanf("%d%d", &n, &m);
    blk = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        qry[i] = {i, l, r};
    }

    sort(qry + 1, qry + 1 + m);

    int l = 1, r = 0;
    for (int i = 1; i <= m; i++) {
        if (qry[i].l == qry[i].r) {
            ans[qry[i].id] = {0, 1};
            continue;
        }
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
        long long blk = (long long) (r - l + 1) * (r - l) / 2;
        long long g = gcd(res, blk);
        ans[qry[i].id] = {res / g, blk / g};
    }
    for (int i = 1; i <= m; i++) {
        printf("%lld/%lld\n", ans[i].first, ans[i].second);
    }
    return 0;
}