#include <bits/stdc++.h>
using namespace std;

int st[200010];

void work() {
    int n, k;
    cin >> n >> k;
    if(k & 1) {
        cout << "YES" << '\n';
        for(int i = 1; i <= n; i += 2) {
            cout << i << " " << i + 1 << '\n';
        }
    } else {
        int cnt = 0;
        vector<pair<int, int> > eve4k;
        for(int i = 1; i <= n; ++i) {
            st[i] = 0;
            if(i % 4 != 0 && i % 2 == 0 && (i + k) % 4 == 0) {
                eve4k.push_back({i, i - 1});
                st[i] = st[i - 1] = 1;
                cnt++;
            }
        }
        if(n / 2 - cnt > n / 4) {
            cout << "NO" << '\n';
            return;
        }
        int pow4 = 1;
        for(int i = 1; i <= n; ++i) {
            if(i % 2 == 1 && st[i] == 0) {
                eve4k.push_back({i, 4 * pow4});
                st[i] = st[4 * pow4] = 1;
                pow4++;
            }
        }
        int t = 0;
        pair<int, int> tmp;
        for(int i = 1; i <= n; ++i) {
            if(i % 2 == 0 && st[i] == 0) {
                if(t == 0) {
                    tmp.first = i;
                    t = 1;
                } else {
                    t = 0;
                    tmp.second = i;
                    eve4k.push_back(tmp);
                }
            }
        }
        cout << "YES" << '\n';
        for(int i = 0; i < eve4k.size(); ++i) {
            cout << eve4k[i].first << " " << eve4k[i].second << '\n';
        }
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        work();
    }
    return 0;
}