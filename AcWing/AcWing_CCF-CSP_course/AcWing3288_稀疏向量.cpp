#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m1, m2;
unordered_map<int, int> p1, p2;

int main () {
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++) {
        int a, b;
        cin >> a >> b;
        p1[a] = b;
    }
    for (int i = 1; i <= m2; i++) {
        int a, b;
        cin >> a >> b;
        p2[a] = b;
    }
    long long res = 0;
    for (auto p : p1) {
        if (p2.count(p.first)) {
            res += (long long) p.second * p2[p.first];
        }
    }
    cout << res << "\n";
    return 0;
}