#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[10010];
int main(){
    cin >> n;
    int maxn = 0, maxidx = 0;
    for(int i = 1; i <= n; ++i){
        int t;
        cin >> t;
        cnt[t] ++;
        if(maxn <= cnt[t]){
            if(maxn == cnt[t]){
                maxidx = min(maxidx, t);
                continue;
            }
            maxn = cnt[t];
            maxidx = t;
        }
    }
    cout << maxidx;
    return 0;
}
