#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n;

int primes[N], cnt;
bool st[N];
long long phi[N];

void init() {
    phi[1] = 1;
    for(int i = 2; i <= n; ++i) {
        if(!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; primes[j] * i <= n; ++j) {
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) {
                phi[primes[j] * i] = primes[j] * phi[i];
                break;
            }
            phi[primes[j] * i] = (primes[j] - 1) * phi[i];
        }
    }
    for(int i = 2; i <= n; ++i) {
        phi[i] += phi[i - 1];
    }
}

int calc(int x) {
    return (1 + x) * x / 2;
}

int main() {
    cin >> n;
    init();
    long long res = 0;
    for(int l = 1; l <= n; ++l) {
        res += (long long) l * ((long long) 2 * phi[n / l] - 1);
    }
    cout << res << endl;
    return 0;
} 