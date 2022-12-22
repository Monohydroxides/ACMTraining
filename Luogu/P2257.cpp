#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e7 + 5;

int primes[N], st[N], cnt, mu[N];
LL sum[N];

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
    for(int i = 0; i < cnt; ++i){
        for(int j = primes[i]; j < N; j += primes[i]){
            sum[j] += mu[j / primes[i]];
        }
    }
    for(int i = 1; i < N; ++i)  sum[i] += sum[i - 1];
}

int main(){
    init();
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        LL res = 0;
        for(int l = 1, r; l <= min(n, m); l = r + 1){
            r = min(n / (n / l), m / (m / l));
            res += (sum[r] - sum[l - 1]) * (LL) (n / l) * (m / l);
        }
        cout << res << endl;
    }
    return 0;
}