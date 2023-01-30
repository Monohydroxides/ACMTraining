#include <bits/stdc++.h>
using namespace std;

int n;
int a[110], di[110];

int fa[110];
int find (int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}


int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> di[i];
        if (i - di[i] >= 1) {
            int pa = find(i), pb = find(i - di[i]);
            fa[pb] = pa;
        }
        if (i + di[i] <= n) {
            int pa = find(i), pb = find(i + di[i]);
            fa[pb] = pa;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (find(i) != find(a[i])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}