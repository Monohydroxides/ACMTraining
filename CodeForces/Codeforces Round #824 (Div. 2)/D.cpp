#include <bits/stdc++.h>
using namespace std;

struct cards {
    int feat[21];
} crd[1010];

void work () {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            cin >> crd[i].feat[j];
        }
    }
    
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}