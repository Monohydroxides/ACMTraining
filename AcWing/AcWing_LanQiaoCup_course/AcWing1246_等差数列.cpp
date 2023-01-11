#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];

int gcd (int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    vector<int> dif;
    for (int i = 2; i <= n; i++) {
        dif.push_back(a[i] - a[i - 1]);
        if (a[i] - a[i - 1] == 0) {
            cout << n << '\n';
            return 0;
        }
    }
    int g = dif[0];
    for (int i = 1; i < dif.size(); i++) {
        g = gcd(g, dif[i]);
    }
    cout << (a[n] - a[1]) / g + 1 << '\n';
    return 0;
}