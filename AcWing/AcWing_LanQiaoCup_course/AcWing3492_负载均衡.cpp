#include <bits/stdc++.h>
using namespace std;

int n, m;
long long cap[200010];
map<int, long long> mp[200010]; // ([id, time, cap])

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &cap[i]);
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        for (auto it : mp[b]) {
            if (it.first > a) break;
            cap[b] += it.second;
            mp[b].erase(it.first);
        }
        // for (int i = 1; i <= n; i++) printf("%lld ", cap[i]);
        // puts("");
        if (cap[b] >= d) {
            cap[b] -= d;
            mp[b][a + c] += d;
            printf("%lld\n", cap[b]);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}