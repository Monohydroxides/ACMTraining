#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    int tot = 0;
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        tot += x; 
        int r = 0;
        for (int j = 1; j <= m; j++) {
            int y;
            cin >> y;
            tot += y;
            r += -y;
        }
        if (r > ans1) {
            ans1 = r;
            ans2 = i;
        }
    }
    cout << tot << " " << ans2 << " " << ans1 << "\n";
    return 0;
}