#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> p;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        p.push_back({l, r});
    }
    sort(p.begin(), p.end());
    int st = -2e9, ed = -2e9;
    for (auto pair : p) {
        if (ed < pair.first) {
            if (ed != -2e9) {
                ans.push_back({st, ed});
            }
            st = pair.first, ed = pair.second;
        } else if (ed < pair.second) {
            ed = pair.second;
        }
    }
    if (st != -2e9 && ed != -2e9) {
        ans.push_back({st, ed});
    }
    printf("%d", ans.size());
    return 0;
}
