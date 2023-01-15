#include <bits/stdc++.h>
using namespace std;

int main () {
    long long a, b, n;
    cin >> a >> b >> n;
    long long res = n / (a * 5 + b * 2) * 7;
    n = n % ((a * 5 + b * 2));
    for (int i = 1; i <= 7; i++) {
        if (n > 0) {
            n -= i <= 5 ? a : b;
            res++;
        } else {
            break;
        }
    }
    cout << res << '\n';
    return 0;
}