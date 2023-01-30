#include <bits/stdc++.h>
using namespace std;

const int inf = 1 << 30;

int n;
int ans;
vector<int> v;

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    v.push_back(inf);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    v.push_back(inf);

    while (n--) {
        int k, j, tmp;
        for (k = 1; k <= n; k++) {
            if (v[k - 1] < v[k + 1]) break;
        }
        tmp = v[k] + v[k - 1];
        for (j = k - 1; j >= 0; j--) {
            if (v[j] > v[k] + v[k - 1]) break;
        }
        v.erase(v.begin() + k - 1);
        v.erase(v.begin() + k - 1);
        v.insert(v.begin() + j + 1, tmp);
        ans += tmp;
        if (n == 1) break;
    }
    cout << ans << '\n';
    return 0;
}