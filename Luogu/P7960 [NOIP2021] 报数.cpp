#include <bits/stdc++.h>
using namespace std;

int pre;
bool st[15000010];
int nxt[15000010];

bool check (int x) {
    while (x) {
        int cur = x % 10;
        if (cur == 7) return true;
        x /= 10;
    }
    return false;
}

void init () {
    for (int i = 1; i <= 15000000; i++) {
        if (st[i]) continue;
        if (check(i)) {
            for (int j = i; j <= 15000000; j += i) {
                st[j] = 1;
            }
            continue;
        }
        nxt[pre] = i;
        pre = i;
    }
}

void work () {
    int n;
    cin >> n;
    if (st[n]) {
        cout << -1 << '\n';
        return;
    }
    cout << nxt[n] << '\n';
}

int main () {
    init();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}