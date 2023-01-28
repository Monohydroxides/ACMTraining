#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int n;
double f[N], g[N];

int main () {
    cin >> n;
    f[n] = g[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        f[i] = f[i + 1] + 1.0 * n / (n - i);
        g[i] = g[i + 1] + 1.0 * i / (n - i) * f[i] + f[i + 1] + 1.0 * n / (n - i);
    }
    cout << fixed << setprecision(2) << g[0] << '\n';
    return 0;
}