#include <bits/stdc++.h>
using namespace std;

const int N = 50;

int n;
int dp[N];

int dfs (int cur) {
    if (cur == 1) return 0;
    if (cur <= 3) return 1;
    if (dp[cur]) return dp[cur];
    return dp[cur] = dfs(cur - 1) + dfs(cur - 2);
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << dfs(i) << " ";
    }
    
    return 0;
}