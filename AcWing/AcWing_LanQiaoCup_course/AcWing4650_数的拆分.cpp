#include <bits/stdc++.h>
using namespace std;
 
const int N = 4e3;
 
int primes[N + 1], cnt;
bool st[N + 1];
 
void init () {
    for (int i = 2; i <= N; ++i) {
        if (!st[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] * i <= N; ++j) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

bool check (long long x) {
    long long l = 1, r = 2e9;
    while (l < r) {
        long long mid = l + r >> 1;
        if (mid * mid < x) l = mid + 1;
        else r = mid;
    }
    if (l * l == x) return true;
    l = 1, r = 2e6;
    while (l < r) {
        long long mid = l + r >> 1;
        if (mid * mid * mid < x) l = mid + 1;
        else r = mid;
    }
    if (l * l * l == x) return true;
    return false;
}
 
void work () {
    long long a;
    cin >> a;
    if (check(a)) {
        cout << "yes\n";
        return;
    }
    for (int i = 0; i < cnt; ++i) {
        if (a % primes[i] == 0) {
            int cnt = 0;
            while (a % primes[i] == 0) {
                a /= primes[i];
                cnt++;
            }
            if (cnt == 1) {
                cout << "no\n";
                return;
            }
        }
    }
    if (!check(a)) {
        cout << "no\n";
        return;
    }
    cout << "yes\n";
}
 
int main () {
    init();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}