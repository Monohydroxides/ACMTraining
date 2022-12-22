#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 50010;

int T;
int a, b, c, d, k;
int primes[N], cnt, st[N], mu[N], sum[N];

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

LL f(int a, int b){
    a /= k, b /= k;
    LL res = 0;
    int n = min(a, b);
    for(int l = 1, r; l <= n; l = r + 1){
        r = min(a / (a / l), b / (b / l));
        r = min(n, r);
        res += (LL) (sum[r] - sum[l - 1]) * (a / l) * (b / l);
    }
    return res;
}

void work(){
    a = 1, c = 1;
    cin >> b >> d >> k;
    cout << f(b, d) - f(a - 1, d) - f(b, c - 1) + f(a - 1, c - 1) << endl;
    return;
}

int main(){
    cin >> T;
    init();
    while(T--)  work();
    return 0;
}