#include <bits/stdc++.h>
using namespace std;

const int mod = 19940417;

int n, m;
int inv6 = 3323403;

int sum1 (int l, int r) {
    int rr = ((long long) (1 + r) * r / 2) % mod;
    int ll = ((long long) (1 + l) * l / 2) % mod;
    return ((rr - ll) % mod + mod) % mod;
}

int sum2 (int l, int r) {
    long long suml = (long long) l * (1 + l) % mod * (2 * l + 1) % mod * inv6 % mod;
    long long sumr = (long long) r * (1 + r) % mod * (2 * r + 1) % mod * inv6 % mod;
    return ((sumr - suml) % mod + mod) % mod;
}

int f (int n) {
    long long res = (long long) n * n % mod;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        res = ((res - (long long) (n / l) * sum1(l - 1, r) % mod) % mod + mod) % mod;
    }
    return res;
}

int g (int n, int m) {
    int minn = min(n, m);
    long long res = (long long) minn * n % mod * m % mod;
    for (int l = 1, r; l <= minn; l = r + 1) {
        r = min(n / (n / l), m / (m / l));
        long long tmp = (long long) sum2(l - 1, r) * (n / l) % mod * (m / l) % mod;
        tmp = ((tmp - ((long long) (n / l) * ((long long) m * sum1(l - 1, r) % mod) % mod) % mod) % mod + mod) % mod;
        tmp = ((tmp - ((long long) (m / l) * ((long long) n * sum1(l - 1, r) % mod) % mod) % mod) % mod + mod) % mod;
        res = (res + tmp) % mod; 
    }
    return res;
}

int main () {
    cin >> n >> m;
    cout << (((long long) f(n) * f(m) % mod - g(n, m)) % mod + mod) % mod << '\n';
    return 0;
}