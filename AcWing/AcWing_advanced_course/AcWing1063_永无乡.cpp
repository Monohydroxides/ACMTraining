#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, m;
int idx;
int root[N];
struct node{
    int s[2], p;
    int v, sz, id;
    void init(int _v, int _p, int _id){
        v = _v, p = _p, id = _id, sz = 1;
    }
}tr[N];

int p[N];

inline int read(){
    int x=0,w=1;
    char ch;ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*w;
}

int find(int x){
    return x == p[x] ? x : p[x] = find(p[x]);
}

void pushup(int x){
    tr[x].sz = tr[tr[x].s[0]].sz + tr[tr[x].s[1]].sz + 1;
}

void rotate(int x){
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}

void splay(int x, int k, int rt){
    while(tr[x].p != k){
        int y = tr[x].p, z = tr[y].p;
        if(z != k){
            if((tr[z].s[0] == y) ^ (tr[y].s[0] == x))   rotate(x);
            else    rotate(y);
        }
        rotate(x);
    }
    if(k == 0)  root[rt] = x;
}

void insert(int x, int v, int id){
    int rtx = root[x], p = 0;
    while(rtx)  p = rtx, rtx = tr[rtx].s[tr[rtx].v < v];
    rtx = id;
    if(p)   tr[p].s[tr[p].v < v] = rtx;
    tr[rtx].init(v, p, id);
    splay(rtx, 0, x);
}

void merge(int x, int y){
    if(tr[y].s[0])  merge(x, tr[y].s[0]);
    if(tr[y].s[1])  merge(x, tr[y].s[1]);
    insert(x, tr[y].v, tr[y].id);
}

int get_kth(int x, int k){
    while(x){
        if(tr[tr[x].s[0]].sz >= k)  x = tr[x].s[0];
        else if(tr[tr[x].s[0]].sz + 1 == k) return tr[x].id;
        else    k -= tr[tr[x].s[0]].sz + 1, x = tr[x].s[1];
    }
    return -1;
}

int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; ++i){
        int v;
        v = read();
        p[i] = root[i] = i;
        tr[i].init(v, 0, i);
    }
    idx = n;
    for(int i = 1; i <= m; ++i){
        int x, y;
        x = read(), y = read();
        x = find(x), y = find(y);
        if(x == y) continue;
        if(tr[root[x]].sz < tr[root[y]].sz) swap(x, y);
        p[y] = x;
        merge(x, root[y]);
    }
    cin >> m;
    for(int i = 1; i <= m; ++i){
        string str;
        int x, y;
        cin >> str;
        x = read(), y = read();
        if(str[0] == 'Q'){
            x = find(x);
            if(tr[root[x]].sz < y)  cout << -1 << endl;
            else    cout << get_kth(root[x], y) << endl;
        }else{
            x = find(x), y = find(y);
            if(x == y) continue;
            if(tr[root[x]].sz < tr[root[y]].sz) swap(x, y);
            p[y] = x;
            merge(x, root[y]);
        }
    }
    return 0;
}
