#include<bits/stdc++.h>
using namespace std;

const int N = 110;

int n, m;
long long a[N], b[N], c[N];

int main () {
    cin >> n >> m;
    c[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], c[i] = c[i - 1] * a[i];
    }
    for (int i = 1; i <= n; i++) {
        long long b = m / c[i - 1] % a[i];
        cout << b << ' ';
        m -= b * c[i - 1];
    }
    return 0;
}
