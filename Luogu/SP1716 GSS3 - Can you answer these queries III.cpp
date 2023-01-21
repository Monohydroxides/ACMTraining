#include <bits/stdc++.h>
using namespace std;

const int N = 500010;

struct node{
    int l, r;
    int tmax, lmax, rmax, sum;
}tr[N * 4];

int n, m, ww[N];

void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].lmax = max(tr[u << 1].sum + tr[u << 1 | 1].lmax, tr[u << 1].lmax);
    tr[u].rmax = max(tr[u << 1 | 1].sum + tr[u << 1].rmax, tr[u << 1 | 1].rmax);
    tr[u].tmax = max(max(tr[u << 1].tmax, tr[u << 1 | 1].tmax), tr[u << 1].rmax + tr[u << 1 | 1].lmax);
}

void pushup(node &a, node &b, node &c){
    a.sum = b.sum + c.sum;
    a.lmax = max(b.sum + c.lmax, b.lmax);
    a.rmax = max(c.sum + b.rmax, c.rmax);
    a.tmax = max(max(b.tmax, c.tmax), b.rmax + c.lmax);
}

void build(int u, int l, int r){
    if(l == r)  {tr[u] = {l, r, ww[l], ww[l], ww[l], ww[l]};}
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int v){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].lmax = tr[u].rmax = tr[u].tmax = tr[u].sum = v;
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid)    modify(u << 1, x, v);
        else            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

node query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r)    return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid < l)     return query(u << 1 | 1, l, r);
    else if(mid >= r)    return query(u << 1, l, r);
    else{
        node left = query(u << 1, l, r), right = query(u << 1 | 1, l, r);
        node res;
        pushup(res, left, right);
        return res;
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &ww[i]);
    build(1, 1, n);
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i){
        int xx, yy, zz;
        scanf("%d%d%d", &xx, &yy, &zz);
        if(xx == 1) {if(yy > zz) {swap(yy, zz);}printf("%d\n", query(1, yy, zz).tmax);}
        else modify(1, yy, zz);
    }
    return 0;
}