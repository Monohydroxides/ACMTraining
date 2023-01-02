// #include <bits/stdc++.h>
// using namespace std;

// int n, m;
// vector<array<int, 3>> e;
// vector<int> x;

// int main () {
//     cin >> n >> m;
//     x.resize(n + 1);
//     for (int i = 1; i <= m; i++) {
//         int op, a, b;
//         cin >> op >> a >> b;
//         switch(op) {
//             case 1: {
//                 e.push_back({a, b, 0});
//                 e.push_back({b, a, 0});
//                 break;
//             }
//             case 2: {
//                 e.push_back({b, a, -1});
//                 break;
//             }
//             case 3: {
//                 e.push_back({a, b, 0});
//                 break;
//             }
//             case 4: {
//                 e.push_back({a, b, -1});
//                 break;
//             }
//             case 5: {
//                 e.push_back({b, a, 0});
//                 break;
//             }
//             default: {
//                 assert(0);
//                 break;
//             }
//         }
//     }
//     for (int i = 1; i <= n; i++) {
//         e.push_back({i, 0, -1});
//     }
//     for (int i = 0; i <= n; i++) {
//         for (auto [u, v, w]: e) {
//             x[v] = min(x[v], x[u] + w);
//         }
//     }
//     for (auto [u, v, w] : e) {
//         if (x[v] > x[u] + w) {
//             cout << -1 << '\n';
//             return 0;
//         }
//     }
//     int res = 0;
//     for (int i = 1; i <= n; i++) {
//         res += x[i] - x[0];
//         // cout << x[i] - x[0] << "\n";
//     }
//     cout << res << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
vector<array<int, 2>> e[N];
vector<long long> x;

vector<bool> vis;
vector<int> cnt;
queue<int> qu;

bool spfa (int st) {
    vis[st] = 1;
    x[st] = 0;
    qu.push(st);
    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        vis[u] = 0;
        for (auto [v, w] : e[u]) {
            if (x[v] > x[u] + w) {
                x[v] = x[u] + w;
                cnt[v]++;
                if (cnt[v] > n) {
                    return 0;
                }
                if (!vis[v]) {
                    qu.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return 1;
}

int main () {
    cin >> n >> m;
    
    x.resize(n + 1);
    vis.resize(n + 1);
    cnt.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        switch(op) {
            case 1: {
                e[b].push_back({a, 0});
                e[a].push_back({b, 0});
                break;
            }
            case 2: {
                if (a == b) {
                    cout << -1 << '\n';
                    return 0;
                }
                e[a].push_back({b, -1});
                break;
            }
            case 3: {
                e[b].push_back({a, 0});
                break;
            }
            case 4: {
                if (a == b) {
                    cout << -1 << '\n';
                    return 0;
                }
                e[b].push_back({a, -1});
                break;
            }
            case 5: {
                e[a].push_back({b, 0});
                break;
            }
            default: {
                assert(0);
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        e[0].push_back({i, -1});
    }

    // for (int i = 1; i <= n; i++) x[i] = -0x3f3f3f3f;

    if (!spfa(0)) {
        cout << "-1\n";
        return 0;
    }

    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res += x[i] - x[0];
        // cout << x[i] - x[0] << '\n';
    }
    cout << -res << '\n';

    return 0;
}