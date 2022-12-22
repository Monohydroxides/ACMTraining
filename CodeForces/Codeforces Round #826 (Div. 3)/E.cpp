#include <bits/stdc++.h>
using namespace std;

int n;
int b[200010];
int dp[200010];

void work () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        dp[i] = 0;
    }
    
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