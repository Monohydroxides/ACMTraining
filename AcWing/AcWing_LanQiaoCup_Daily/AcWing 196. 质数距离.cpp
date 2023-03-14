#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define int long long

LL st[50010], primes[50010], cnt;
LL isprime[1000010];

signed main(){
    int l, r;
    for(int i = 2; i <= 50000; ++i){
        if(!st[i])  primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= r; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0)  break;
        }
    }
    while(cin >> l >> r){
        memset(isprime, 0, sizeof isprime);
        for(int p = 0; p < cnt; ++p){
            int pri = primes[p];
            int t = max((LL)2, (l + pri - 1) / pri);
            for(int j = pri * t; j <= r; j += pri){
                isprime[j - l] = 1;
            }
        }
        vector<int> res;
        for(int i = 0; i <= r - l; ++i){
            if(!isprime[i] && i + l != 1){
                res.push_back(i + l);
            }
        }
        if(res.size() < 2){
            cout << "There are no adjacent primes." << endl;
            continue;
        }
        int minloc = -1, maxloc = -1;
        int minn = 1e9 + 10, maxn = -1;
        for(int i = 0; i < res.size() - 1; ++i){
            if(res[i + 1] - res[i] > maxn){
                maxn = res[i + 1] - res[i];
                maxloc = i;
            }
            if(res[i + 1] - res[i] < minn){
                minn = res[i + 1] - res[i];
                minloc = i;
            }
        }
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n", res[minloc], res[minloc + 1], res[maxloc], res[maxloc + 1]);
    }
    return 0;
}