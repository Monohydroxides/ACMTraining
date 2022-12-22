#include <bits/stdc++.h>
using namespace std;



void work () {
    int n;
    cin >> n;
    n -= 3;
    int mid = n / 3;
    int las = 1;
    int maxn = n - mid - las;
    cout << min(abs(mid - las), min(abs(las - maxn), abs(mid - maxn))) << '\n';
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}