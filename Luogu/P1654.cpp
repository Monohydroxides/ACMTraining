#include <bits/stdc++.h>
using namespace std;

int n;
double a[100010];
double dp1[100010], dp2[100010], dp3[100010];

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        dp1[i] = (dp1[i - 1] + 1) * a[i];
        dp2[i] = (dp2[i - 1] + 2 * dp1[i - 1] + 1) * a[i];
        dp3[i] = dp3[i - 1] + (3 * dp2[i - 1] + 3 * dp1[i - 1] + 1) * a[i];  
    }
    cout << fixed << setprecision(1) << dp3[n] << '\n';
    return 0;
}