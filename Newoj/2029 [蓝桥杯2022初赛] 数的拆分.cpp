#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e3;
 
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
 
void work () {
    long long a;
    cin >> a;
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
    if (a > 1) {
        cout << "no\n";
        return;
    }
    cout << "yes\n";
}
 
int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    init();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}