#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2 * 1e6 + 10;

int n;
int primes[N], st[N], phi[N], cnt;
LL phisum[N];


void init(){
    phi[1] = 0;
    for(int i = 2; i < N; ++i){
        if(!st[i])  primes[cnt++] = i, phi[i] = i - 1;
        for(int j = 0; primes[j] * i < N; ++j){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0){
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
    for(int i = 1; i < N; ++i){
        phisum[i] = phisum[i - 1] + phi[i];
    }
}

int main(){
    init();
    cin >> n;
    LL res = 0;
    for(int d = 1; d <= n; ++d){
        res += (LL)d * (2 * phisum[n / d] + 1);
    }
    res -= (LL)(n) * (n + 1) / 2;
    res /= 2;
    cout << res << endl;
    return 0;
}