#include <bits/stdc++.h>
using namespace std;
 
const int mod = 998244353;
 
int n;
int pi[100010];
int ex[100010];
 
int norm (int x) {
    return (x % mod + mod) % mod;
}
 
int qmi (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (long long) res * a % mod;
        }
        a = (long long) a * a % mod;
        b >>= 1;
    }
    return res;
}
 
int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        pi[i] = (long long) xi * qmi(yi, mod - 2) % mod;
    }
    for (int i = 1; i <= n; ++i) {
        ex[i] = (long long) (ex[i - 1] + 1) * qmi(norm(1 - pi[i]), mod - 2) % mod;
        ex[i] = norm(ex[i]);
    }
    cout << ex[n] << '\n';
    return 0;
}