#include <bits/stdc++.h>

typedef long long ll;

int P;

int qmi(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1)   res = (ll) res * a % P;
        a = (ll) a * a % P;
        b >>= 1;
    }
    return res;
}

void work() {
    int a, n, q;
    std::unordered_map<int, int> restb;
    std::cin >> P >> a >> n >> q;
    std::pair<int, int> st[1010];
    int sst[1010];
    for(int i = 1; i <= n; ++i) {
        std::cin >> st[i].first >> st[i].second;
        sst[i] = qmi(st[i].first, P - 2);
    }
    int cur = 1;
    for(int i = 0; i <= 200000; ++i) {
        if(restb.count(cur))    break;
        restb[cur] = i;
        cur = (ll) cur * a % P;
    }
    for(int i = 1; i <= q; ++i) {
        int x;
        std::cin >> x;
        int cnt = 0;
        if(!x) {
            for(int i = 1; i <= n; ++i) {
                if(st[i].first == 0) {
                    ++cnt;
                }
            }
        } else {
            for(int j = 1; j <= n; ++j) {
                int tmp = (ll) x * sst[j] % P;
                // std::cout << x << " " << j << " " << tmp << " " << restb[tmp] << std::endl;
                if(restb.count(tmp) && restb[tmp] <= st[j].second) {
                    ++cnt;
                }
            }
        }
        std::cout << cnt << std::endl;
    }
    return;
}

int main() {
    std::cin.tie(0), std::cout.tie(0);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while(T--)  work();
    return 0;
}