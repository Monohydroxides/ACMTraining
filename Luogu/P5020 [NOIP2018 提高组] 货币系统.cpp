#include <bits/stdc++.h>
using namespace std;

int T;

int a[101];
int flg[25001];

void work(){
    int n;
    cin >> n;
    int res=n;
    memset(flg,0,sizeof flg);
    for(int i=1;i<=n;++i)   cin >> a[i];
    sort(a+1,a+1+n);
    vector<int> rep;
    rep.push_back(0);
    for(int i=1;i<=n;++i){
        if(flg[a[i]]){
            res--;
            continue;
        }
        for(int k=1;k*a[i]<=a[n];++k){
            for(int p=0;p<rep.size();++p){
                if(rep[p]+k*a[i]>a[n])  continue;
                if(!flg[rep[p]+k*a[i]]) rep.push_back(rep[p]+k*a[i]);
                flg[rep[p]+k*a[i]]=1;
            }
        }
    }
    cout << res << endl;
    return;
}

int main(){
    cin >> T;
    while(T--)  work();
    return 0;
}