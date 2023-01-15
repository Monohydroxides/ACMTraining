#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int ans[n + 1];
    for (int i = 1; i <= n; i++) {
        ans[i] = max(i - 1, n - i) * 2;
        cout << ans[i] << "\n";
    }
    return 0;
}