#include <bits/stdc++.h>
using namespace std;

int main () {
    int k;
    cin >> k;
    double res = 0;
    int cur = 1;
    while (res <= k) {
        res += 1 / double(cur);
        cur++;
    }
    cout << cur - 1 << '\n';
    return 0;
}