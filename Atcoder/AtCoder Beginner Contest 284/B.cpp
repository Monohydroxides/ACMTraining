#include <bits/stdc++.h>
using namespace std;

int main () {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x % 2 == 1) res++;
        }
        cout << res << '\n';
    }   
    return 0;
}