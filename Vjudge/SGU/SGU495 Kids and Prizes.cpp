#include <bits/stdc++.h>
using namespace std;

int n, m;
double f[100010];

int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        f[i] = f[i - 1] + (1.0 * n - f[i - 1]) / n;
    }
    cout << fixed << setprecision(10) << f[m] << '\n';
    return 0;
}