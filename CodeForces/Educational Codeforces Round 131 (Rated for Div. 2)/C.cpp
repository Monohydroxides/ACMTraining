#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, m;
int a[200010];
struct node{
    int l, r;
    int maxn, minn, maxloc, minloc;
}tr[800010];

void pushup(int u){
    if(tr[u << 1].maxn < tr[u << 1 | 1].maxn){
        tr[u].maxn = tr[u << 1 | 1].maxn;
        tr[u].maxloc = tr[u << 1 | 1].maxloc;
    }else{
        tr[u].maxn = tr[u << 1].maxn;
        tr[u].maxloc = tr[u << 1].maxloc;
    }
    if(tr[u << 1].minn < tr[u << 1 | 1].minn){
        tr[u].minn = tr[u << 1].minn;
        tr[u].minloc = tr[u << 1].minloc;
    }else{
        tr[u].minn = tr[u << 1 | 1].minn;
        tr[u].minloc = tr[u << 1 | 1].minloc;
    }
}

void build(int u, int l, int r){
    tr[u].l = l, tr[u].r = r;
    if(l == r){
        tr[u].maxloc = tr[u].minloc = l;
        tr[u].maxn = 0;
        tr[u].minn = 0;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int v){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].maxn += v, tr[u].minn += v;
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid)    modify(u << 1, x, v);
        else    modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

int querymax(int u, int l, int r, int& loc){
    if(tr[u].l >= l && tr[u].r <= r){
        loc = tr[u].maxloc;
        return tr[u].maxn;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if(mid < r) v = querymax(u << 1 | 1, l, r, loc);
    if(mid >= l){
        int tmploc;
        int t = querymax(u << 1, l, r, tmploc);
        if(t > v){
            v = t;
            loc = tmploc;
        }
    }
    return v;
}

int querymin(int u, int l, int r, int& loc){
    if(tr[u].l >= l && tr[u].r <= r){
        loc = tr[u].minloc;
        return tr[u].minn;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if(mid < r) v = querymin(u << 1 | 1, l, r, loc);
    if(mid >= l){
        int tmploc;
        int t = querymin(u << 1, l, r, tmploc);
        if(t < v){
            v = t;
            loc = tmploc;
        }
    }
    return v;
}

void work(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) cin >> a[i];
    build(1, 1, n);
    for(int i = 1; i <= m; ++i){
        modify(1, a[i], 1);
    }
    int res = 1e9, loc;
    while(res >= querymax(1, 1, n, loc)){
        res = querymax(1, 1, n, loc);
        modify(1, loc, -1);
        querymin(1, 1, n, loc);
        modify(1, loc, 2);
    }
    cout << res << endl;
    return;
}

int main(){
    int T;
    cin >> T;
    while(T--)  work();
    return 0;
}