#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, int> fi, las;

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (fi.count(x)) {
            las[x] = i - 1;
        } else {
            fi[x] = i - 1;
        }
    }
    while (m--) {
        int x;
        cin >> x;
        if (!fi.count(x)) {
            cout << -1 << " " << -1 << '\n';
        } else if (!las.count(x)) {
            cout << fi[x] << " " << fi[x] << '\n';
        } else {
            cout << fi[x] << " " << las[x] << '\n';
        }
    }
    return 0;
}