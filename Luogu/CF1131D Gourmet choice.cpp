#include <bits/stdc++.h>
using namespace std;

int n, m;
int x[2010], cnt[2010];
bool inq[2010];
vector<array<int, 2>> e[2010];

int spfa () {
    queue<int> qu;
    for (int i = 1; i <= n + m; i++) {
        qu.push(i);
        inq[i] = 1;
        cnt[i] = 1;
        x[i] = 1;
    }
    while (qu.size()) {
        int cur = qu.front();
        qu.pop();
        inq[cur] = 0;
        for (auto [v, w] : e[cur]) {
            if (x[v] < x[cur] + w) {
                x[v] = x[cur] + w;
                if (!inq[v]) {
                    qu.push(v);
                    cnt[v]++;
                }
                if (cnt[v] > n + m) return -1;
            }
        }
    }
    return 0;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= n + m; j++) {
            char ch;
            cin >> ch;
            if (ch == '>') {
                e[j].push_back({i, 1});
            } else if (ch == '=') {
                e[i].push_back({j, 0});
                e[j].push_back({i, 0});
            } else if (ch == '<') {
                e[i].push_back({j, 1});
            }
        }
    }
    if (spfa() == -1) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << '\n';
    for (int i = n + 1; i <= n + m; i++) {
        cout << x[i] << " ";
    }
    cout << '\n';
    return 0;
}