#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int head[N], to[N], nxt[N], w[N], eid;

void add (int a, int b, int c) {
    to[eid] = b, nxt[eid] = head[a], w[eid] = c, head[a] = eid++;
}

int n, m;
int dist[N];
bool inq[N];
queue<int> qu;

void spfa () {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    qu.push(1);
    inq[1] = 1;
    while (!qu.empty()) {
        auto cur = qu.front();
        qu.pop();
        inq[cur] = 0;
        for (int i = head[cur]; ~i; i = nxt[i]) {
            int v = to[i];
            if (dist[v] > dist[cur] + w[i]) {
                dist[v] = dist[cur] + w[i];
                if (!inq[v]) {
                    qu.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) {
        cout << "impossible\n";
    } else {
        cout << dist[n] << "\n";
    }
}

int main () {
    memset(head, -1, sizeof head);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    spfa();
    return 0;
}