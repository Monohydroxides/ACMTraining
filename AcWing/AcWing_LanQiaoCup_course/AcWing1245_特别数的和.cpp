#include <bits/stdc++.h>
using namespace std;

int n;
long long res;

bool check (int x) {
    while (x) {
        int cur = x % 10;
        if (cur == 2 || cur == 0 || cur == 1 || cur == 9) return true;
        x /= 10;
    }
    return false;
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++)
        if (check(i)) res+=i;
    cout << res << '\n';
    return 0;
}