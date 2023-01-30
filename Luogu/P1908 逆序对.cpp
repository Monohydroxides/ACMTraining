#include <bits/stdc++.h>
using namespace std;

int n;
int a[500010];
vector<int> dis;

int find (int x) {
    int l = 0, r =  dis.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (dis[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l;
}

long long tr[500010];
int lowbit (int x) { return x & (-x); }

void add (int k, int x) {
    for (; k <= n; k += lowbit(k)) {
        tr[k] += x;
    }
}

int query (int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
        res += tr[x];
    } 
    return res;
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dis.push_back(a[i]);
    }
    sort(dis.begin(), dis.end());
    dis.erase(unique(dis.begin(), dis.end()), dis.end());
    long long res = 0;
    for (int i = n; i >= 1; i--) {
        // cout << find(a[i]) << '\n';
        int l = find(a[i]) + 1;
        res += query(l - 1);
        add(l, 1);
    }
    cout << res << '\n';
    return 0;
}