#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e5+10;

int n, m;
int a[N];
LL c[N],ic[N];

int lowbit(int x){return x&(-x);}

void add(LL x, LL v){
    LL p=x;
    for(; x<=n; x+=lowbit(x))   c[x]+=v, ic[x]+=p*v;
}

LL query(LL x){
    LL res=0;
    LL p=x;
    for(; x; x-=lowbit(x))  res+=(p+1)*c[x]-ic[x];
    return res;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i)   cin >> a[i],add(i,a[i]-a[i-1]);
    for(int i=1;i<=m;++i){
        char op;
        LL x, y, k;
        cin >> op >> x >> y;
        if(op=='Q'){
            cout << query(y) - query(x-1) << endl;
        }else{
            cin >> k;
            add(x,k), add(y+1,-k);
        }
    }
    return 0;
}
