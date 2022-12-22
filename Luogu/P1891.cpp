#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 10;

int mu[N], primes[N], cnt;
bool st[N];
int sum1[N], sum2[N];

void init() {
    mu[1] = 1;
    for(int i = 2; i < N; ++i) {
        if(!st[i]) {
            primes[cnt++] = i;
            mu[i] = -1;
        }
        for(int j = 0; primes[j] * i < N; ++j) {
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) {
                break;
            }
            mu[primes[j] * i] = -mu[i];
        }
    }
    for(int i = 1; i < N; ++i) {
        for(int j = 1; i * j < N; ++j) {
            sum1[i * j] += (j + 1) * j / 2 * i * mu[i];
        }
    }
    for(int i = 1; i < N; ++i) {
        for(int j = 1; i * j < N; ++j) {
            sum2[i * j] += sum1[i];
        }
    }
}

signed main() {
    init();
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        cout << n * sum2[n] << endl;
    }
    return 0;
}