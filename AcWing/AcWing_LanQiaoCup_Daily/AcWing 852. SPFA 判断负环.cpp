#include <bits/stdc++.h>
using namespace std;

const int N = 2010, M = 1e4 + 10;

int n, m;
int head[N], nxt[M], to[M], wt[M], eid;

void add (int a, int b, int c) {
    to[eid] = b, wt[eid] = c, nxt[eid] = head[a], head[a] = eid++;
}

int inq[N], cnt[N];
int dist[N];

bool spfa () {
    queue<int> qu;
    for (int i = 1; i <= n; i++) {
        inq[i] = 1;
        qu.push(i);
    }
    while (qu.size()) {
        int cur = qu.front();
        qu.pop();
        inq[cur] = 0;
        for (int i = head[cur]; ~i; i = nxt[i]) {
            int v = to[i];
            if (dist[v] > dist[cur] + wt[i]) {
                dist[v] = dist[cur] + wt[i];
                cnt[v] = cnt[cur] + 1;
                if (cnt[v] > n) {
                    return true;
                }
                if (!inq[v]) {
                    qu.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
    return false;
}

int main () {
    memset(head, -1, sizeof head);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    if (spfa()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}