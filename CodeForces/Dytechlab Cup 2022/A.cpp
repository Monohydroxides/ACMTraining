#include <bits/stdc++.h>
using namespace std;

void work () {
    int n, k;
    string str;
    cin >> n >> k;
    cin >> str;
    map<char, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[str[i]]++;
    }
    string res;
    for (int i = 1; i <= k; ++i) {
        for (char it = 'a'; it <= 'z'; ++it) {
            if (it - 'a' >= n / k) {
                res += it;
                break;
            }
            if (mp.count(it) && mp[it] > 0) {
                mp[it]--;
            } else {
                res += (char) (it);
                break;
            }
        }
    }
    cout << res << '\n';
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