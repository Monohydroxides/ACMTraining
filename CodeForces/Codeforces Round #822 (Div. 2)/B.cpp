#include <bits/stdc++.h>
using namespace std;

int f[510][510];

void init () {
    for (int i = 1; i <= 500; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == 1 || j == i) {
                f[i][j] = 1;
            }
        }
    }
}

void work () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << f[i][j] << " ";
        }
        cout << '\n';
    }
    
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    init();
    while (T--) {
        work();
    }
    return 0;
}