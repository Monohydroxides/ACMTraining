#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10, INF=1e8;

int n;

struct node{
    int l, r, cnt, size, key, val;
}tr[N];
int rt, idx;

void pushup(int p){
    tr[p].size=tr[tr[p].l].size+tr[tr[p].r].size+tr[p].cnt;
}

void zig(int &p){
    int q=tr[p].l;
    tr[p].l=tr[q].r, tr[q].r=p, p=q;
    pushup(tr[p].r), pushup(p);
}

void zag(int &p){
    int q=tr[p].r;
    tr[p].r=tr[q].l, tr[q].l=p, p=q;
    pushup(tr[p].l), pushup(p);
}

int get_node(int key){
    tr[++idx].key=key;
    tr[idx].cnt=tr[idx].size=1;
    tr[idx].val=rand();
    return idx;
}

void build(){
    rt=get_node(-INF),tr[rt].r=get_node(INF);
        pushup(rt);
    if(tr[rt].val<tr[tr[rt].r].val) zag(rt);
}

void ins(int &p, int key){
    if(!p)  p=get_node(key);
    else{
        if(tr[p].key==key)  tr[p].cnt++;
        else{
            if(tr[p].key>key){
                ins(tr[p].l, key);
                if(tr[tr[p].l].val>tr[p].val)   zig(p);
            }else{
                ins(tr[p].r, key);
                if(tr[tr[p].r].val>tr[p].val)   zag(p);
            }
        }
    }
    pushup(p);
}

void del(int &p, int k){
    if(!p)  return;
    if(tr[p].key==k){
        if(tr[p].cnt>1) tr[p].cnt--;
        else if(tr[p].l || tr[p].r){
            if(!tr[p].r || tr[tr[p].l].val>tr[tr[p].r].val){
                zig(p);
                del(tr[p].r,k);
            }else{
                zag(p);
                del(tr[p].l,k);
            }
        }else   p=0;
    }else{
        if(tr[p].key>k)del(tr[p].l, k);
        else   del(tr[p].r, k);
    }
    pushup(p);
}

int get_rank_by_key(int p, int key){
    if(!p)  return -1;
    if(tr[p].key==key)  return tr[tr[p].l].size+1;
    if(tr[p].key>key)   return get_rank_by_key(tr[p].l, key);
    return tr[p].cnt+tr[tr[p].l].size+get_rank_by_key(tr[p].r, key);
}

int get_key_by_rank(int p, int rk){
    if(!p)  return -1;
    if(tr[tr[p].l].size>=rk)   return get_key_by_rank(tr[p].l,rk);
    if(tr[tr[p].l].size+tr[p].cnt>=rk)  return tr[p].key;
    return get_key_by_rank(tr[p].r,rk-tr[p].cnt-tr[tr[p].l].size);
}

int get_prev(int p, int key){
    if(!p)  return -INF;
    if(tr[p].key>=key)  return get_prev(tr[p].l, key);
    return max(tr[p].key, get_prev(tr[p].r, key));
}

int get_next(int p, int key){
    if(!p)  return INF;
    if(tr[p].key<=key)  return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));
}

int main(){
    build();
    cin >> n;
    for(int i=1;i<=n;++i){
        int op, x;
        cin >> op >> x;
        if(op==1)       ins(rt,x);
        else if(op==2)  del(rt,x);
        else if(op==3)  cout << get_rank_by_key(rt, x)-1 << endl;
        else if(op==4)  cout << get_key_by_rank(rt, x+1) << endl;
        else if(op==5)  cout << get_prev(rt, x) << endl;
        else            cout << get_next(rt, x) << endl;
    }
    return 0;
}
