#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2e5+10;

int n;
int a[N], gr[N], ls[N];
int c[N];

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
    scanf("%d",&n);
    for(int i=1;i<=n;++i)   scanf("%d",&a[i]);
    for(int i=1;i<=n;++i){
        ls[i]=query(a[i]-1);
        gr[i]=query(n)-query(a[i]);
        add(a[i],1);
    }
    memset(c, 0, sizeof c);
    LL resa=0, resb=0;
    for(int i=n;i>=1;--i){
        resa+=(LL)ls[i]*query(a[i]-1);
        resb+=(LL)gr[i]*(query(n)-query(a[i]));
        add(a[i],1);
    }
    cout << resb << " " << resa << endl;
    return 0;
}
