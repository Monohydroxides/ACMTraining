#include <bits/stdc++.h>
using namespace std;

int cnt[510];

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        x += 100;
        cnt[x]++;
    }
    int flg = 1;
    for (int i = 0; i <= 300; i++) {
        if (cnt[i]) {
            if (flg) {
                flg = 0;
            } else {
                cout << i - 100 << '\n';
                return 0;
            }
        } 
    }
    cout << "NO\n";
    return 0;
}