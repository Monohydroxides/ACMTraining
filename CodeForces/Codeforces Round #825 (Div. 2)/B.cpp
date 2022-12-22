#include <bits/stdc++.h>
using namespace std;

int a[100010];
int b[100010];

int gcd (int a, int b) {
    return b == 0? a: gcd(b, a % b);
}

void work () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    b[1] = a[1];
    a[n + 1] = 1;
    for (int i = 2; i <= n + 1; ++i) {
        b[i] = a[i - 1] * a[i] / gcd(a[i - 1], a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (gcd(b[i], b[i + 1]) != a[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}