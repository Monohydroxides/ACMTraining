#include <bits/stdc++.h>
using namespace std;

int arr[100010];

void work () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    vector< pair<int, int> > res;
    if ((arr[1] % 2) && (arr[2] % 2)) {
        for (int i = 3; i <= n; ++i) {
            if (arr[i] % 2 == 0) {
                res.push_back({1, i});
            }
        }
        for (int i = n - 1; i >= 1; --i) {
            res.push_back({i, n});
        }
    } else if (!(arr[1] % 2) && !(arr[2] % 2)) {
        for (int i = 3; i <= n; ++i) {
            if (arr[i] % 2 == 1) {
                res.push_back({1, i});
            }
        }
        for (int i = n - 1; i >= 1; --i) {
            res.push_back({i, n});
        }
    } else if ((arr[1] % 2) && !(arr[2] % 2)) {
        for (int i = 3; i <= n; ++i) {
            if (arr[i] % 2 == 1) {
                res.push_back({2, i});
            }
        }
        for (int i = n - 1; i >= 2; --i) {
            res.push_back({i, n});
        }
        for (int i = 2; i <= n; ++i) {
            res.push_back({i - 1, i});
        }
    } else {
        for (int i = 2; i <= n; ++i) {
            if (arr[i] % 2 == 1) {
                res.push_back({1, i});
            }
        }
        for (int i = n - 1; i >= 1; --i) {
            res.push_back({i, n});
        }
    }
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].first << " " << res[i].second << '\n';
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