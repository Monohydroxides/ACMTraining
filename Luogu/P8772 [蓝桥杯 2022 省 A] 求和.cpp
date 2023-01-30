#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<long long> pre(n + 2); 
    pre[n + 1] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        pre[i] = pre[i + 1] + a[i];
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        res = res + (long long) a[i] * pre[i + 1];
    }
    cout << res << '\n';
    return 0;
}