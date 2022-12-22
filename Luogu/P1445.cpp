#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int mod = 1e9 + 7, N = 1e6 + 10;

int st[N], primes[N], cnt;

int main(){
    int n;
    LL res = 1;
    cin >> n;
    for(int i = 2; i <= n; ++i){
        if(!st[i])  primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0)  break;
        }
    }
    for(int i = 0; i < cnt; ++i){
        int pri = primes[i];
        int ans = 0;
        for(int j = 1; pow(pri, j) <= n; ++j){
            ans += n / pow(pri, j);
        }
        res = (LL)res * (ans * 2 + 1) % mod;
    }
    cout << res << endl;
    return 0;
}