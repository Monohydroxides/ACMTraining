#include <bits/stdc++.h>
using namespace std;

void work () {
    map<int, int> cntx, cnty;
    for (int i = 1; i <= 3; ++i) {
        int x, y;
        cin >> x >> y;
        cntx[x] = 1, cnty[y] = 1;
    }
    if (cntx.size() == 2 && cnty.size() == 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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