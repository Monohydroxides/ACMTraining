#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
int head[N], nxt[N * 2], to[N * 2], eid;

void add (int a, int b) {
    to[eid] = b, nxt[eid] = head[a], head[a] = eid++;
}

void work1 () {
    
}

void work2 () {
    string str;
    cin >> str;
    str = " " + str;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        add(i + 1, p);
        add(p, i + 1);
    }
    int res = 0;
    function<void(int, int)> dfs = [&] (int u, int father) -> void {
        int tag = 0;
        for (int i = head[u]; ~i; i = nxt[i]) {
            int v = to[i];
            if (v == father) continue;
            tag = 1;
            dfs(v, u);
        }
        if (!tag) res++;
    };
    dfs(1, -1);
    cout << "win!\n";
    cout << res << '\n';
}

int main () {
    cin >> n;
    memset(head, -1, sizeof head);
    if (0) {
        work1();
    } else {
        work2();
    }
    return 0;
}