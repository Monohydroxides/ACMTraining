#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e7 + 1;

int n, m;
int mod = 20101009;
int primes[N], cnt, st[N], mu[N], smu[N], sum[N];

void init(){
    mu[1] = 1;
    int k = min(m, n);
    for(int i = 2; i <= k; ++i){
        if(!st[i])  primes[cnt++] = i, mu[i] = -1;
        for(int j = 0; primes[j] * i < N; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0)  {
                mu[i * primes[j]] = 0; 
                break;
            }
            mu[primes[j] * i] = -mu[i];
        }
    }
    for(int i = 1; i <= k; ++i){
        smu[i] = smu[i - 1] + mu[i];
    }
    for(int i = 1; i <= k; ++i){
        sum[i] = (sum[i - 1] + (LL) i * i % mod * (mu[i] + mod) % mod) % mod;
    }
}

int g(int x, int i){
    return x / (x / i);
}

LL calc(int a, int b){
    return (LL)(1 + a) * a / 2 % mod * ((LL)(1 + b) * b / 2 % mod) % mod;
}

int func(int a, int b){
    int res = 0, r;
    for(int l = 1; l <= min(a, b); l = r + 1){
        r = min(g(a, l), g(b, l));
        res = (res + (LL)(sum[r] - sum[l - 1]) * calc(a / l, b / l) % mod) % mod;
    }
    return res;
}

int work(){
    int res = 0;
    for(int l = 1, r; l <= min(n, m); l = r + 1){
        r = min(g(n, l), g(m, l));
        res = (res + (LL)(r - l + 1) * (l + r) / 2 % mod * func(n / l, m / l) % mod) % mod;
    }
    return (res + mod) % mod; 
}

int main(){
    cin >> n >> m;
    init();
    cout << work() << endl;
    return 0;
}