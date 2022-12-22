#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1001][1001];

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    } 
    for (int j = 1; j <= m; ++j) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i][j] == '#') {
                cnt++;
            }
        } 
        cout << cnt << " ";
    }
    cout << '\n';
    return 0;
}