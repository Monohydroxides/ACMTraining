#include <bits/stdc++.h>
using namespace std;

int fa[27];
int find (int x) {
    if (x == fa[x]) {
        return x;
    }
    return fa[x] = find(fa[x]);
}

void work () {
    int n;
    string str;
    cin >> n >> str;
    str = " " + str;
    map<char, char> mp;
    string res;
    int vis[26];
    memset(vis, 0, sizeof vis);
    int count = 0;
    for (int i = 0; i <= 26; ++i) {
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        char chr = str[i];
        if (mp.count(chr)) {
            res += mp[chr];
            continue;
        }
        for (char it = 'a'; it <= 'z'; ++it) {
            if (it == chr) {
                continue;
            }
            if (vis[it - 'a']) {
                continue;
            }
            int pa = find(chr - 'a'), pb = find(it - 'a');
            if (pa == pb) {
                if (count < 25) {
                    continue;
                }
            }
            res += (char) it;
            mp[chr] = it;
            vis[it - 'a'] = 1;
            count++;
            if (pa != pb) {
                fa[pb] = pa;
            }
            break;
        }
    }
    cout << res << endl;
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}