#include <bits/stdc++.h>
using namespace std;

int n;
int a[200010];

int main () {
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res ^= a[i];
    }
    for (int i = 1; i <= n; i++) {
        int r = a[i];
        cout << (r ^ res) << " ";
    }
    return 0;
}