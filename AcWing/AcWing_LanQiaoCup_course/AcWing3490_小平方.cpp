#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, res = 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
        if (i * i % n < (n + 1) / 2) res++;
    }
    cout << res << '\n';
    return 0;
}