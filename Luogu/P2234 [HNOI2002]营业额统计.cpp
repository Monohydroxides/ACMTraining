#include <bits/stdc++.h>
using namespace std;

const int N = 32768, INF=1e7;

int n, res;
struct node{
    int l, r;
    int key, val;
}tr[N];
int rt, idx;

int aabs(int x)  {return x>=0?x:-x;}

int get_node(int key){
    tr[++idx].key=key;
    tr[idx].val=rand();
    return idx;    
}

void zig(int &p){
    int q=tr[p].l;
    tr[p].l=tr[q].r, tr[q].r=p, p=q;
}

void zag(int &p){
    int q=tr[p].r;
    tr[p].r=tr[q].l, tr[q].l=p, p=q;
}

void build(){
    rt=get_node(-INF), tr[rt].r=get_node(INF);
    if(tr[tr[rt].r].val>tr[rt].val) zag(rt);
}

void ins(int &p, int key){
    if(!p)  p=get_node(key);
    else{
        if(tr[p].key==key)  return;
        else if(tr[p].key<key){
            ins(tr[p].r, key);
            if(tr[tr[p].r].val>tr[p].val)   zag(p);
        }else{
            ins(tr[p].l, key);
            if(tr[tr[p].l].val>tr[p].val)   zig(p);
        }
    }
}

int get_prev(int p, int key){
    if(!p)  return -INF;
    if(tr[p].key==key)  return key;
    if(tr[p].key>key)  return get_prev(tr[p].l, key);
    return max(tr[p].key, get_prev(tr[p].r, key));
}

int get_next(int p, int key){
    if(!p)  return INF;
    if(tr[p].key==key)  return key;
    if(tr[p].key<=key)  return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));
}

int main(){
    build();
    cin >> n;
    for(int i=1;i<=n;++i){
        int x;
        cin >> x;
        if(i==1)    res+=x;
        else{
            res+=min(aabs(x-get_prev(rt, x)), aabs(x-get_next(rt, x)));
        }
        ins(rt, x);
    }
    cout << res << endl;
    return 0;
}