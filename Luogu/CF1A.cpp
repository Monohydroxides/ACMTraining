#include <bits/stdc++.h>
using namespace std;

long long n, m, a, res;

int main () {
    cin >> n >> m >> a;
    res = (m + a - 1) / a;
    res = (n + a - 1) / a * res;
    cout << res << '\n';
    return 0;
}