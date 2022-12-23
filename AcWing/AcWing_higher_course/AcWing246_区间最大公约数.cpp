#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 500010;

struct node{
    int l, r;
    LL sum, g;
}tr[N * 4];

int n, m;
LL w[N];

LL gcd(LL a, LL b){
    return b ? gcd(b, a % b) : a;
}

void pushup(node &rot, node &l, node &r){
    rot.sum = l.sum + r.sum;
    rot.g = gcd(l.g, r.g);
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}


void build(int u, int l, int r){
    if(l == r)  {tr[u] = {l, r, w[l] - w[l - 1], w[l] - w[l - 1]};return;}
    if(l > r)   return;
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, LL v){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].sum += v, tr[u].g += v;
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid)modify(u << 1, x, v);
        else        modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

node query(int u, int l, int r){
    if(l > r)   return {0, 0, 0, 0};
    if(tr[u].l >= l && tr[u].r <= r)    return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid < l)     return query(u << 1 | 1, l, r);
    else if(mid >= r)   return query(u << 1, l, r);
    else{
        node left = query(u << 1, l, r);
        node right = query(u << 1 | 1, l, r);
        node res;
        pushup(res, left, right);
        return res;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) scanf("%lld", &w[i]);
    build(1, 1, n);
    for(int i = 1; i <= m; ++i){
        int aa, bb;
        LL cc;
        char op[2];
        scanf("%s%d%d", op, &aa, &bb);
        if(*op == 'C'){         
            scanf("%lld", &cc);
            modify(1, aa, cc);
            if(bb + 1 <= n) modify(1, bb + 1, -cc);
        }else{
            printf("%lld\n", abs(gcd(query(1, 1, aa).sum, query(1, aa + 1, bb).g)));
        }
    }
    return 0;
}
