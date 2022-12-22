#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, m;

struct node{
    int s[2], p;
    int flag, id, sz;
    void init(int _id, int _p){
        id = _id, p = _p;
    }
}tr[N];

int root, idx;

void pushup(int u){
    tr[u].sz = tr[tr[u].s[0]].sz + tr[tr[u].s[1]].sz + 1;
}

void pushdown(int u){
    if(tr[u].flag){
        swap(tr[u].s[0], tr[u].s[1]);
        tr[tr[u].s[0]].flag ^= 1, tr[tr[u].s[1]].flag ^= 1;
        tr[u].flag = 0;
    }
}

void rotate(int x){
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}

void splay(int x, int k){
    while(tr[x].p != k){
        int y = tr[x].p, z = tr[y].p;
        if(z != k){
            if((tr[z].s[0] == y) ^ (tr[y].s[0] == x))   rotate(y);
            else                                        rotate(x);
        }
        rotate(x);
    }
    if(!k)  root = x;
}

void insert(int v){
    int u = root, p = 0;
    while(u)    p = u, u = tr[u].s[tr[u].id < v];
    u = ++idx;
    if(p)   tr[p].s[v > tr[p].id] = u;
    tr[u].init(v, p);
    splay(u, 0);
}

int get_kth(int k){
    int u = root;
    while(1){
        pushdown(u);
        if(tr[tr[u].s[0]].sz >= k)   u = tr[u].s[0];
        else if(tr[tr[u].s[0]].sz + 1 == k) return u;
        else    k -= tr[tr[u].s[0]].sz + 1, u = tr[u].s[1];
    }
    return -1;
}

void output(int u){
    pushdown(u);
    if(tr[u].s[0])  output(tr[u].s[0]);
    if(tr[u].id >= 1 && tr[u].id <= n)  cout << tr[u].id << " ";
    if(tr[u].s[1])  output(tr[u].s[1]);
}

int main(){
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i <= n + 1; ++i){
        insert(i);
    }
    for(int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        int l = get_kth(x), r = get_kth(y + 2);
        splay(l, 0), splay(r, l);
        tr[tr[r].s[0]].flag ^= 1;
    }
    output(root);
    return 0;
}