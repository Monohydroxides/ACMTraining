#include <bits/stdc++.h>
using namespace std;

int T;
int a[35];

void work(){
    int n;
    cin >> n;
    int ok=1;
    int cnt=0;
    for(int i=1;i<=n;++i)   cin >> a[i];
    for(int i=n-1;i>=1;--i){
        while(a[i] >= a[i+1]){
            a[i]/=2;
            cnt++;
            if(a[i]==0 && a[i]>=a[i+1]){
                ok=0;
                break;
            }
        }
    }
    if(!ok){
        cout << -1 << endl;
    }else{
        cout << cnt << endl;
    }
    return;
}

int main(){
    cin >> T;
    while(T--)  work();
    return 0;
}