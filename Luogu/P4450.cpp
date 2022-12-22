#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e6 + 5;

int primes[N], st[N], mu[N], sum[N], cnt;

void init(){
    mu[1] = 1;
    for(int i = 2; i < N; ++i){
        if(!st[i])  primes[cnt++] = i, mu[i] = -1;
        for(int j = 0; primes[j] * i < N; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0)  break;
            mu[primes[j] * i] = -mu[i];  
        }
    }
    for(int i = 1; i < N; ++i){
        sum[i] = sum[i - 1] + mu[i];
    }
}

int main(){
    init();
    int a, b, d;
    cin >> a >> b >> d;
    LL res = 0;
    a /= d, b /= d;
    for(int l = 1, r; l <= min(a, b); l = r + 1){
        r = min(a / (a / l), b / (b / l));
        res += (LL) (sum[r] - sum[l - 1]) * (a / l) * (b / l);
    }
    cout << res << endl;
    return 0;
}