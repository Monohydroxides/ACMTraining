#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

long long tr[N];
vector<int> dsc;

int find (int x) {
    int l = 1, r = dsc.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (dsc[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int lowbit (int x) {
    return x & (-x);
}

void add (int x, int k) {
    for (; x <= dsc.size(); x += lowbit(x)) {
        tr[x] += k;
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
    dsc.push_back(-1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dsc.push_back(a[i]);
    }
    sort(dsc.begin(), dsc.end());
    dsc.erase(unique(dsc.begin(), dsc.end()), dsc.end());
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res += query(dsc.size()) - query(find(a[i]));
        add(find(a[i]), 1);
    }
    cout << res << '\n';
    return 0;
}