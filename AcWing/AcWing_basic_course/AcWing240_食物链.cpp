#include <bits/stdc++.h>

using namespace std;

int n, m;
int p[100010], val[100010], idx;
int res;

int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);
        val[x] += val[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main() {
    cin >> n >> m;
    int x, a, b;
    for(int i = 1; i <= n; ++i) p[i] = i;
    while (m--) {
        cin >> x >> a >> b;
        if (a > n || b > n) ++res;
        else if (x == 2 && a == b) ++res;
        else {
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                p[pa] = pb;
                val[pa] = x == 1 ? (val[b] - val[a]) : (val[b] + 1 - val[a]);
            } else if((x == 1 && (val[a] - val[b]) % 3) || (x == 2 && ((val[a] - val[b] - 1) % 3)))   ++res;
        }
    }
    cout << res << endl;
    return 0;
}
