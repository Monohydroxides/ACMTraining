#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> mp;

int main () {
    cin >> n;
    int cnt = 0;
    vector<int> a(n);
    for (auto &i: a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    for (auto i: a) {
        if (i < 0) {
            mp[i] = 1;
        } else {
            if (mp[-i]) {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}