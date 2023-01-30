#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1010];
int f[1010];
map<int, int> mp;

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                if (arr[i] == 0 && arr[j] == 0) {
                    res = max(res, mp[0]);
                    continue;
                }
                f[0] = arr[i], f[1] = arr[j];
                mp[arr[i]]--, mp[arr[j]]--;
                int cnt = 2;
                while (mp[f[cnt - 2] + f[cnt - 1]] > 0) {
                    f[cnt] = f[cnt - 2] + f[cnt - 1];
                    mp[f[cnt - 2] + f[cnt - 1]]--;
                    cnt++;
                }
                res = max(res, cnt);
                for (int i = 0; i < cnt; ++i) {
                    mp[f[i]]++;
                }
            }
        }
    }
    cout << res << '\n';
    return 0;
}