#include <bits/stdc++.h>
using namespace std;

int sten[100010];
int que[100010];
map<int, int> mp, stmp;

void work() {
    int n, q;
    cin >> n >> q;
    int maxn = 0, maxid = 0;
    int cnt = 0;
    mp.clear();
    stmp.clear();
    for(int i = 1; i <= n; ++i) que[i] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> sten[i];
        stmp[sten[i]] = i;
        if(maxn < sten[i]) {
            maxn = sten[i];
            maxid = i;
        }
        if(cnt == 0 || sten[i] > que[cnt]) {
            cnt++;
            que[cnt] = sten[i];
            mp[i] = cnt;
        }
    }
    int id, kth;
    for(int i = 1; i <= q; ++i) {
        cin >> id >> kth;
        if(!mp.count(id) || id > maxid || (id == 1 && sten[id] < sten[id + 1]) || (id == 2 && sten[id] < sten[id - 1])) {
            cout << 0 << '\n';
        } else {
            if(sten[id] == maxn) {
                cout << max(0, kth - max(id - 2, 0)) << '\n';
            } else {
                if(max(id - 2, 0) >= kth) {
                    cout << 0 << '\n';
                } else {
                    kth -= max(id - 2, 0);
                    int res = min(kth, stmp[que[mp[id] + 1]] - id - 1);
                    cout << res << '\n';
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        work();
    }
    return 0;
}