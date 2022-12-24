#include <bits/stdc++.h>
using namespace std;

int n;

map<int, map<int, int> > mp;
map<int, vector<int> > cnt;
int ans[5];

int main () {
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
        cnt[x].push_back(y);
    }
    for (auto r: cnt) {
        vector<int> rw = cnt[r.first];
        sort(rw.begin(), rw.end());
        for (int pt: rw) {
            int rf = r.first;
            if (mp[r.first][pt - 1] && mp[r.first][pt + 1] && mp[r.first - 1][pt] && mp[r.first + 1][pt]) {
                ans[mp[r.first + 1][pt + 1] + mp[r.first + 1][pt - 1] + mp[r.first - 1][pt + 1] + mp[r.first - 1][pt - 1]] += 1;
            }
        }
    }
    for (int i: ans) {
        cout << i << '\n';
    }
    return 0;
}