#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int n, m, s;
struct chip {
    string func;
    vector<int> input;
} chi[510];

int head[5010], to[500010], nxt[500010], eid;
bool ans[5010];
int inq[5010];

int qry[10010][3010];

void add (int a, int b) {
    to[eid] = b, nxt[eid] = head[a], head[a] = eid++;
}

queue<int> check () {
    queue<int> qu, ansq;
    for (int i = 1; i <= m + n; i++) {
        if (i > m) inq[i] = chi[i - m].input.size();
        else inq[i] = 0;
    }
    for (int i = 1; i <= m + n; i++) {
        if (!inq[i]) {
            qu.push(i);
        }
    }
    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        ansq.push(u);
        for (int i = head[u]; ~i; i = nxt[i]) {
            int v = to[i];
            inq[v]--;
            if (inq[v] == 0) {
                qu.push(v);
            }
        }
    }
    return ansq;
}

bool get_status (int id) {
    if (chi[id].func == "NOT") {
        return !ans[chi[id].input[0]];
    } else if (chi[id].func == "AND") {
        for (auto fr : chi[id].input) {
            if (ans[fr] == 0) {
                return 0;
            }
        }
        return 1;
    } else if (chi[id].func == "OR") {
        for (auto fr : chi[id].input) {
            if (ans[fr] == 1) {
                return 1;
            }
        }
        return 0;
    } else if (chi[id].func == "XOR") {
        int ansr = 0;
        for (auto fr : chi[id].input) {
            ansr ^= ans[fr];
        }
        return ansr;
    } else if (chi[id].func == "NAND") {
        for (auto fr : chi[id].input) {
            if (ans[fr] == 0) {
                return 1;
            }
        }
        return 0;
    } else if (chi[id].func == "NOR") {
        for (auto fr : chi[id].input) {
            if (ans[fr] == 1) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

void work () {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        string func, port;
        int k;
        cin >> func >> k;
        chi[i].func = func;
        for (int j = 1; j <= k; j++) {
            cin >> port;
            int portnum;
            if (port[0] == 'I') { 
                portnum = stoi(port.substr(1));
            } else {
                portnum = stoi(port.substr(1)) + m;
            }
            add(portnum, i + m);
            chi[i].input.push_back(portnum);
        } 
    }
    queue<int> top = check();
    int flg = 1;
    if (top.size() != n + m) {
        flg = 0;
    }
    cin >> s;
    queue<int> bak = top;
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> qry[i][j];
        }
    }
    if (!flg) {
        for (int i = 1; i <= s; i++) {
            int si;
            cin >> si;
            for (int j = 1; j <= si; j++) {
                int x;
                cin >> x;
            }
        }
        cout << "LOOP\n";
        return;
    }
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= m; j++) {
            ans[j] = qry[i][j];
        }
        top = bak;
        while (top.size()) {
            int u = top.front();
            top.pop();
            if (u <= m) continue;
            ans[u] = get_status(u - m);
        }
        int si;
        cin >> si;
        for (int j = 1; j <= si; j++) {
            int x;
            cin >> x;
            cout << ans[x + m] << " ";
        }
        cout << "\n";
    }
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        memset(head, -1, sizeof head);
        memset(inq, 0, sizeof inq);
        eid = 0;
        for (int i = 1; i <= n; i++) {
            chi[i].input.clear();
        }
        work();
    }
    return 0;
}