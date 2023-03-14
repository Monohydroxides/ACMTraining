#include <bits/stdc++.h>
using namespace std;

int main () {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << __gcd(a, b) << "\n";
    }
    return 0;
}