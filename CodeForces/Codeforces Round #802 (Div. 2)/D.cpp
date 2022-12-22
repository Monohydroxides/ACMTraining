#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int T;

int a[200010];
LL pre[200010];

void work(){
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    LL res = a[1];
    for(int i = 2; i <= n; ++i){
        res = max(res, (pre[i] + i - 1) / i);
    }
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        if(x < res){
            cout << -1 << endl;
        }else{
            cout << (pre[n] + x - 1) / x << endl;
        }
    }
}

int main(){
    T = 1;
    while(T--)  work();
    return 0;
}