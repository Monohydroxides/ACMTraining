#include <bits/stdc++.h>
using namespace std;

int n, m, k;

struct pic {
    int g[31][31];
    int cnt;
    int id;
} pics[110];

int main () {
    cin >> n >> m >> k;
    for (int i = 1; i <= k + 1; i++) {
        pics[i].id = i;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                char ch;
                cin >> ch;
                pics[i].g[j][k] = ch == '1';
            }
        }
    }
    for (int i = 1; i <= k + 1; i++) {
        for (int j = 2; j < n; j++) {
            for (int k = 2; k < m; k++) {
                if (pics[i].g[j][k] != pics[i].g[j - 1][k] && pics[i].g[j][k] != pics[i].g[j + 1][k]
                && pics[i].g[j][k] != pics[i].g[j][k + 1] && pics[i].g[j][k] != pics[i].g[j][k - 1]) {
                    pics[i].cnt++;
                }
            }
        }
    }
    sort(pics + 1, pics + k + 2, [&] (pic a, pic b) {
        return a.cnt > b.cnt;
    });
    // for (int i = 1; i <= k + 1; i++) {
    //     cout << pics[i].cnt << " ";
    // }
    // cout << '\n';
    cout << pics[1].id << '\n';
    vector<array<int, 3>> opt;
    for (int i = 2; i <= k + 1; i++) {
        for (int j = 2; j < n; j++) {
            for (int k = 2; k < m; k++) {
                if (pics[i].g[j][k] != pics[i - 1].g[j][k]) {
                    opt.push_back({1, j, k});
                }
            }
        }
        opt.push_back({2, pics[i].id});
    }
    cout << opt.size() << '\n';
    for (auto [u, v, w] : opt) {
        if (u == 1) {
            cout << u << " " << v << " " << w << '\n';
        } else {
            cout << u << " " << v << '\n';
        }
    }
    return 0;
}