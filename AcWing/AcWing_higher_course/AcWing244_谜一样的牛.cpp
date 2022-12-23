#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];
int b[100010];

int f[100010];
int lowbit(int x){return x&(-x);}
void add(int x, int k){
    for(;x<=n;x+=lowbit(x)){
        f[x]+=k;
    }
}
int query(int x){
    int sum=0;
    for(;x;x-=lowbit(x)){
        sum+=f[x];
    }
    return sum;
}

int main(){
    cin >> n;
    add(1,1);
    for(int i=2;i<=n;++i)   cin >> a[i], add(i,1);
    for(int i=n;i>=1;--i){
        int l=1,r=n;
        while(l<r){
            int mid=l+r>>1;
            int qry=query(mid);
            if(qry<a[i]+1){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        b[i]=l;
        add(l,-1);
    }
    for(int i=1;i<=n;++i){
        cout << b[i] << endl;
    }
    return 0;
}
