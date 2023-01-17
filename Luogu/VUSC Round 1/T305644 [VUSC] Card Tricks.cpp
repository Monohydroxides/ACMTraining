// https://www.luogu.com.cn/problem/T305644?contestId=96985
// 132 / 330 pts

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, q, p;
int a[N];
struct node {
    int l, r;
    int lo, ro;
    int val;
} tr[N * 2];
int rot[N], idx;
int ans[N];
int pre[N];

template<typename T> 
void read (T &x) {
    x = 0;
    int f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c=='-') 
            f = -1;
        c=getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    x *= f;
}
template<typename T, typename ... Args>
void read (T &x, Args& ... y) {
    read(x);
    read(y...);
}

int build (int l, int r) {
    int p = ++idx;
    tr[p].lo = l, tr[p].ro = r;
    if(l == r) {
        tr[p].val = a[l];
        return p;
    }
    int mid = l + r >> 1;
    tr[p].l = build(l, mid);
    tr[p].r = build(mid + 1, r);
    return p;
}

int modify (int p, int l, int r, int v) {
    int q = ++idx;
    tr[q] = tr[p];
    if (tr[q].lo == tr[q].ro) {
        tr[q].val |= v;
        return q;
    }
    int mid = tr[q].lo + tr[q].ro >> 1;
    if (mid >= l) {
        tr[q].l = modify(tr[q].l, l, r, v);
    }
    if (mid < r) {
        tr[q].r = modify(tr[q].r, l, r, v);
    }
    return q;
}

int query (int p, int x) {
    if (tr[p].lo == tr[p].ro) return tr[p].val;
    int mid = tr[p].lo + tr[p].ro >> 1;
    if (x <= mid) return query(tr[p].l, x);
    else return query(tr[p].r, x);
}

int main () {
    read(n, q, p);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
    }
    if (n <= 1000 && q <= 1000) {   
        rot[0] = build(1, n);
        for (int i = 1; i <= q; i++) {
            int l, r, v;
            read(l, r, v);
            rot[i] = modify(rot[i - 1], l, r, v);
        }
        for (int i = 1; i <= n; i++) {
            int l = 0, r = q + 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (query(rot[mid], i) > p) r = mid;
                else l = mid + 1;
            }
            if (l == q + 1) l = -1;
            cout << l << ' ';
        }
    } else {
        int Case = 3;
        vector<array<int, 3>> qry(q + 1);
        for (int i = 1; i <= q; i++) {
            read(qry[i][0], qry[i][1], qry[i][2]);
            if (qry[i][0] != qry[i][1]) {
                Case = 4;
            }
        }
        if (Case == 3) {
            for (int i = 1; i <= n; i++) {
                ans[i] = -1;
                if (a[i] > p) ans[i] = 0;
            }
            for (int i = 1; i <= q; i++) {
                a[qry[i][0]] |= qry[i][2];
                if (ans[qry[i][0]] == -1 && a[qry[i][0]] > p) {
                    ans[qry[i][0]] = i;
                }
            }
            for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        } else {
            for (int i = 1; i <= q; i++) {
                pre[i] = pre[i - 1] | qry[i][2];
            }
            for (int i = 1; i <= n; i++) {
                int l = 0, r = q + 1;
                while (l < r) {
                    int mid = l + r >> 1;
                    if ((a[i] | pre[mid]) > p) r = mid;
                    else l = mid + 1;
                }
                if (l == q + 1) l = -1;
                cout << l << " ";
            }
        }
    }
    return 0;
}