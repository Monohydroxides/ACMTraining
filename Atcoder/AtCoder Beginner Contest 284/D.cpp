#include <bits/stdc++.h>
using namespace std;

const int N = 3e6;

long long primes[N + 10], cnt;
bool st[N + 10];

void init () {
    for (int i = 2; i <= N; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= N; j++) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break; 
        }
    }
}

int check (long long x) {
    long long l = 1, r = 3e9;
    while (l < r) {
        long long mid = l + r >> 1;
        if (mid * mid >= x) r = mid;
        else l = mid + 1;
    }
    if (l * l == x) return l;
    return 0;
}


int main () {
    init();
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        for (int i = 0; i < cnt; i++) {
            long long x = primes[i];
            if (n % x == 0) {
                long long res = check(n / x);
                if (res) {
                    cout << res << " " << x << '\n';
                } else {
                    cout << x << " " << (n / (x * x)) << '\n';
                }
                break;
            }
        }
    }
    return 0;
}