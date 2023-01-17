// https://www.luogu.com.cn/problem/T305292?contestId=96985
// 66 / 330 pts

#include <bits/stdc++.h>
using namespace std;

using i128 = __int128;

const int N = 1e5, M = 2e5;

long long n, q;
int head[N], nxt[M], to[M], eid;
int tag[N];
int vis[N];

vector<long long> dsc;
vector<array<long long, 2>> opt(q + 1);
unordered_map<long long, int> mp;

template<typename T> 
void read (T &x) {
    x = 0;
    int f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c=='-') 
            f = -1;
        c=getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    x *= f;
}
template<typename T, typename ... Args>
void read (T &x, Args& ... y) {   
    read(x);
    read(y...);
}

int gcd (int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int find (long long x) {
    int l = 0, r = dsc.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (dsc[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

void add (int a, int b) {
    to[eid] = b, nxt[eid] = head[a], head[a] = eid++;
}

int dfs (int u, int father, int flg) {
    vis[u] = flg;
    int ans = 1;
    for (int i = head[u]; ~i; i = nxt[i]) {
        int v = to[i];
        if (v == father || tag[v] || vis[v] == flg) continue;
        ans += dfs(v, u, flg);
    }
    return ans;
}

int main () {
    memset(head, -1, sizeof head);
    read(n, q);
    if (n <= 100000 && q <= 10000) {
        for (int i = 2; i <= n; i++) {
            int j = i;
            while (j * i < n) {
                add(j * i, i);
                add(i, j * i);
                j = j * i;
            }
        }
        for (int i = 1; i <= q; i++) {
            int op, x;
            read(op, x);
            if (op == 1) {
                cout << dfs(x, -1, i) << '\n';
            } else {
                tag[x] = 1;
            }
        }
    } else {
        for (int i = 1; i <= q; i++) {
            read(opt[i][0], opt[i][1]);
            dsc.push_back(opt[i][1]);
            mp[opt[i][1]] = 1;
        }
        int m = opt[1][1];
        for (int i = 2; i <= q; i++) {
            m = gcd(m, opt[i][1]);
        }
        sort(dsc.begin(), dsc.end());
        dsc.erase(unique(dsc.begin(), dsc.end()), dsc.end());
        for (i128 i = m * m; i <= n; i *= m) {
            if (mp[i]) {
                add(find(m), find(i));
                add(find(i), find(m));
            }
        }
        for (auto [k, v] : mp) {
            if (k == m) continue;
            for (i128 t = k * k; t <= n; t *= k) {
                if (mp[t]) {
                    add(find(t), find(k));
                    add(find(k), find(t));
                }
            }
        }
        for (int i = 1; i <= q; i++) {
            int op = opt[i][0];
            long long x = opt[i][1];
            if (op == 1) {
                cout << dfs(find(x), -1, i) << '\n';
            } else {
                tag[find(x)] = 1;
            }
        }
    }
    return 0;
}
