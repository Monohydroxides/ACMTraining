#include <bits/stdc++.h>
using namespace std;

int k, n;
int s[110], f[10010];

int sg(int x){
    if(f[x] != -1)  return f[x];
    unordered_set<int> sett;
    for(int i = 1; i <= k; ++i){
        int t = s[i];
        if(x - t >= 0)  sett.insert(sg(x - t));
    }
    for(int i = 0;; ++i)    if(!sett.count(i))  return f[x] = i;
}

int main(){
    memset(f, -1, sizeof f);
    cin >> k;
    for(int i = 1; i <= k; ++i) cin >> s[i];
    cin >> n;
    int res = 0, x;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        res ^= sg(x);
    }
    if(res == 0) puts("No");
    else    puts("Yes");
    return 0;
}
