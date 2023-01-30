#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f, N = 101000;

int n, minn, L, R, tot;
LL delta;

int root, idx;
struct node{
    int s[2], p;
    int sz, v;
    void init(int _v, int _p){
        p = _p, v = _v;
    }
}tr[N];

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

void splay(int x, int k){
    while(tr[x].p != k){
        int y = tr[x].p, z = tr[y].p;
        if(z != k){
            if((tr[z].s[0] == y) ^ (tr[y].s[0] == x))   rotate(x);
            else                                        rotate(y);
        }
        rotate(x);
    }
    if(k == 0)  root = x;
}

int insert(int v){
    int u = root, p = 0;
    while(u)    p = u, u = tr[u].s[tr[u].v < v];
    u = ++idx;
    if(p)   tr[p].s[v > tr[p].v] = u;
    tr[u].init(v, p);
    splay(u, 0);
    return u;
}

int get(int v){
    int u = root, res;
    while(u){
        if(tr[u].v >= v)    res = u, u = tr[u].s[0];
        else                u = tr[u].s[1];
    }
    return res;
}

int get_kth(int k){
    int u = root;
    while(1){
        if(tr[tr[u].s[0]].sz >= k)  u = tr[u].s[0];
        else if(tr[tr[u].s[0]].sz + 1 == k)  return tr[u].v;
        else    k -= tr[tr[u].s[0]].sz + 1, u = tr[u].s[1];
    }
    return -1;
}

int main(){
    cin.tie(0);
    cin >> n >> minn;
    R = insert(INF), L = insert(-INF);
    while(n--){
        string str;
        int x;
        cin >> str >> x;
        if(str[0] == 'I'){
            if(x < minn) continue;
            insert(x - delta);
            tot ++;
        }else if(str[0] == 'A'){
            delta += x;
        }else if(str[0] == 'S'){
            delta -= x;
            R = get(minn - delta);
            splay(R, 0), splay(L, R);
            tr[L].s[1] = 0;
            pushup(L), pushup(R);
        }else{
            if(tr[root].sz - 2 < x) cout << -1 << endl;
            else cout << get_kth(tr[root].sz - x) + delta << endl;
        }
    }
    cout << tot - tr[root].sz + 2 << endl;
    return 0;
}