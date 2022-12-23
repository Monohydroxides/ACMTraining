#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n, m;
int a[N], c[N];

int lowbit(int x){return x&(-x);}  

void add(int x, int v){
    for(; x<=n; x+=lowbit(x))   c[x]+=v;
}

int query(int x){
    int res=0;
    for(; x; x-=lowbit(x))  res+=c[x];
    return res;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i)   cin >> a[i];
    for(int i=1;i<=n;++i)   add(i,a[i]-a[i-1]);
    for(int i=1;i<=m;++i){
        char op;
        int x, y, k;
        cin >> op >> x;
        if(op=='Q'){
            cout << query(x) << endl;
        }else{
            cin >> y >> k;
            add(x,k),add(y+1,-k);
        }
    }
    return 0;
}
