#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int las = -1;
    for (int l = 1; l <= n;) {
        int r = l + 1;
        while (r <= n && a[l] == a[r]) {
            r++;
        }
        int len = r - l;
        if (las == -1) las = len;
        else if (las != len) {
            cout << "NO\n";
            return 0;
        }
        l = r;
    }
    cout << "YES\n";
    return 0;
}