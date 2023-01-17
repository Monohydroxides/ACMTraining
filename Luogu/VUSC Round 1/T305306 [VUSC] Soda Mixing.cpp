// https://www.luogu.com.cn/problem/T305306?contestId=96985
// 300 / 330 pts

#include <bits/stdc++.h>
using namespace std;

using i128 = __int128;

int n;
int a[100010];

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (i128 state = 1; state < (((i128) 1) << n); state++) {
        i128 j = state;
        int cur = 0, id = 0;
        vector<int> res;
        while (j) {
            if (j & 1) {
                cur ^= a[id];
                res.push_back(id + 1);
            }
            j >>= 1;
            id++;
        }
        if (cur == 0) {
            cout << res.size() << '\n';
            for (auto it : res) {
                cout << it << " ";
            }
            return 0;
        }
    }
}