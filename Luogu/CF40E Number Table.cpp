#include <bits/stdc++.h>
using namespace std;

int n, m, mod;
int ex;
int fir[1010], fic[1010];
int rer[1010], rec[1010];

int qmi (int a, int b) {
    long long res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = (long long) a * a % mod;
        b >>= 1;
    }
    return res;
}

int main () {
    cin >> n >> m;    
    cin >> ex;
    
    if ((n & 1) ^ (m & 1)) {
        cout << 0 << '\n';
        return 0;
    }
    int sw = 0;
    if (n < m) {
        swap(n, m);
        sw = 1;
    }
    for (int i = 1; i <= n; i++) {
        rer[i] = 1;
    }
    for (int j = 1; j <= m; j++) {
        rec[j] = 1;
    }
    for (int i = 1; i <= ex; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        if (sw) {
            rer[y] *= v;
            rec[x] *= v;
            fir[y]++;    
            fic[x]++;
        } else {
            rer[x] *= v;
            rec[y] *= v;
            fir[x]++;
            fic[y]++;
        }
    }
    cin >> mod;
    int ans = 1;
    int f = 1;
    for (int i = 1; i <= n; i++) {
        if (!fir[i] && f) {
            f = 0;
            continue;
        }
        if (fir[i] == m && rer[i] == 1) {
            cout << 0 << '\n';
            return 0;
        }
        if (fir[i] != m) {
            ans = 1ll * ans * qmi(2, m - fir[i] - 1) % mod;
        }
    }
    cout << ans << '\n';
    return 0;
}