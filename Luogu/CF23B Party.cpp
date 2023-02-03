#include <bits/stdc++.h>
using namespace std;

int main () {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << max(0, n - 2) << "\n";
    }
    return 0;
}