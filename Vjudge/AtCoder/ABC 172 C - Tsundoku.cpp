#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main () {
    cin >> n >> m >> k;
    vector<int> a(n + 1, 0), b(m + 1, 0), presuma(n + 1, 0), presumb(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        presuma[i] = presuma[i - 1] + a[i]; 
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        presumb[i] = presumb[i - 1] + b[i];
    }
    int apt = 0;
    while (apt <= n && k >= presuma[apt]) apt++;
    apt--;
    int bpt = 0;
    int ans = 0;
    while (apt >= 0) {
        while (bpt <= m && k - presuma[apt] - presumb[bpt] >= 0) bpt++;
        bpt--;
        ans = max(ans, apt + bpt);
        apt--;
    }
    cout << ans << '\n';
    return 0;
}