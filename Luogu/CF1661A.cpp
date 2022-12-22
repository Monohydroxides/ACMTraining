#include <bits/stdc++.h>
using namespace std;

int T;
long long a[26], b[26];

void work(){
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)   cin >> a[i];
    for(int i=1;i<=n;++i)   cin >> b[i];
    long long ans = 0;
    for(int i=1;i<=n-1;++i){
        ans+=min(abs(a[i+1]-a[i])+abs(b[i+1]-b[i]), abs(a[i+1]-b[i])+abs(b[i+1]-a[i]));
    }
    cout << ans << endl;
    return;
}

int main(){
    cin >> T;
    while(T--)  work();
    return 0;
}