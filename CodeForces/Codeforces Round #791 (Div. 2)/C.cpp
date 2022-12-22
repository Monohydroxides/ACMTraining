#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define all(a) ((a).begin(), (a).end())
#define debug(a) cout << "Debug: " << #a << ": " << a << "\n"
#define per(i, a, b, c) for (int i = a; i < b; i += c)
#define pere(i, a, b, c) for (int i = a; i <= b; i += c)
#define rep(i, a, b, c) for (int i = a; i > b; i -= c)
#define repe(i, a, b, c) for (int i = a; i >= b; i -= c)
#define mst(a, x) memset(a, x, sizeof a)

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 998244353;

int T;
int n, q;
int tr[100010], trr[100010];
int lowbit(int x) { return x & (-x); }
void add(int x, int c, int st) {
    if (st == 1)
        for (int i = x; i <= n; i += lowbit(i))
            tr[i] += c;
    else
        for (int i = x; i <= n; i += lowbit(i))
            trr[i] += c;
}
int sum(int x, int st) {
    int res = 0;
    if (st == 1)
        for (int i = x; i; i -= lowbit(i))
            res += tr[i];
    else
        for (int i = x; i; i -= lowbit(i))
            res += trr[i];
    return res;
}

void work() {
    cin >> n >> q;
    for (int i = 1; i <= q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            add(x, 1, 0);
            add(y, 1, 1);
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
            add(x, -1, 0);
            add(y, -1, 1);
        } else {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (checkx(x1, x2) || checky(y1, y2)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return;
}

int main() {
    cin.tie(0);
    // cin >> T;
    T = 1;
    while (T--)
        work();
    return 0;
}