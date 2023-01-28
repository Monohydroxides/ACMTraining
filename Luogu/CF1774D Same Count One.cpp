#include <bits/stdc++.h>
using namespace std;

struct node {
    int r1, r2;
    int pos;
};

void work () {
    int n, m;
    cin >> n >> m;
    int arr[n + 1][m + 1];
    int cntall = 0;
    int cntrow[n + 1];
    memset(cntrow, 0, sizeof cntrow);
    map<int, int> rowtag[n + 1];
    queue< pair<int, int> > ned, giv;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j]) {
                cntrow[i]++;
                cntall++;
                rowtag[i][j] = 1;
            }
        }
    }
    if (cntall % n) {
        cout << -1 << '\n';
        return;
    }
    int avg = cntall / n;
    for (int i = 1; i <= n; ++i) {
        if (cntrow[i] < avg) {
            ned.push({i, avg - cntrow[i]});
        } else if (cntrow[i] > avg) {
            giv.push({i, cntrow[i] - avg});
        }
    }
    vector<node> res;
    while (ned.size()) {
        auto cur = ned.front();
        ned.pop();
        int satis = 0;
        while (cur.second) {
            while (giv.size()) {
                auto can = giv.front();
                giv.pop();
                for (auto [k, v]: rowtag[can.first]) {
                    if (v == 1) {
                        if (!rowtag[cur.first][k]) {
                            rowtag[cur.first][k] = 1;
                            rowtag[can.first][k] = 0;
                            can.second -= 1;
                            cur.second -= 1;
                            res.push_back({can.first, cur.first, k});
                            if (cur.second == 0) {
                                satis = 1;
                                break;
                            }
                        }
                    }
                    if (can.second == 0) {
                        break;
                    }
                }
                if (can.second) {
                    giv.push(can);
                }
                if (satis) {
                    break;
                }
            }
        }
    }
    cout << res.size() << '\n';
    for (auto cur_res: res) {
        cout << cur_res.r1 << " " << cur_res.r2 << " " << cur_res.pos << '\n';
    }
    return;
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