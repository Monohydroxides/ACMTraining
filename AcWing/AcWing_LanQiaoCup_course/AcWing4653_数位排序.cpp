#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, m;
int a[N];
int cnt[N];

int get (int a) {
    int res = 0;
    while (a) {
        res += a % 10;
        a /= 10;
    }
    return res;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = i, cnt[i] = get(i);
    sort(a + 1, a + 1 + n, [] (int a, int b) {
        if (cnt[a] == cnt[b]) return a < b;
        else return cnt[a] < cnt[b];
    });
    cout << a[m] << '\n';
    return 0;
}