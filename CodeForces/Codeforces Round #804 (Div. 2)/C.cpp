#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int T;

int a[100010];
map<int, int> mp;

void work(){
    int n;
    cin >> n;
    mp.clear();
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        mp[a[i]] = i;
    }
    LL res = 1;
    int l = mp[0], r = mp[0];
    for(int i = 1; i < n; ++i){
        if(mp[i] > l && mp[i] < r){
            res = res * (r - l - i + 1) % mod;
        }else{
            l = min(l, mp[i]), r = max(r, mp[i]);
        }
    }
    cout << res << endl;
}

int main(){
    cin >> T;
    while(T--)  work();
    return 0;
}

