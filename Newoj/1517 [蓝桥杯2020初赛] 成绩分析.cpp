#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int sum = 0, maxn = numeric_limits<int>::min(), minn = numeric_limits<int>::max();
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum += x;
        maxn = max(maxn, x);
        minn = min(minn, x);
    }
    cout << maxn << '\n' << minn << '\n';
    cout << fixed << setprecision(2) << (double) sum / (double) n << '\n';
    return 0;
}