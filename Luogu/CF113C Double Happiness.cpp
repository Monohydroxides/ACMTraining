#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

const int N = 3e8;

int l, r;
int ans;
bitset<N + 1> st;

int main () {
    cin >> l >> r;
    st[1] = 1;
    for (long long i = 2; i * i <= r; i++){
        if(!st[i]) {
            for (long long j = i * i; j <= r; j += i) {
                st[j] = 1;
            }
        }
    }
    for (int i = max(l, 5); i <= r; i += 4) {
        while ((i - 1) % 4 != 0) i++;
        if (i <= r && !st[i]) {
            ans++;
        }
    }
    cout << ans + (l <= 2 && r >= 2) << '\n';
    return 0;
}