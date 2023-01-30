#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

struct TrieNode {
    int fail;
    int vis[26];
    int endtag;
} AC[N];

int tot = 0;

void build (string str) {
    int len = str.size();
    int p = 0;
    for (int i = 0; i < len; ++i) {
        if (!AC[p].vis[str[i] - 'a']) {
            AC[p].vis[str[i] - 'a'] = ++tot;
        }
        p = AC[p].vis[str[i] - 'a'];
    }
    AC[p].endtag++;
}

void getFail () {
    queue<int> qu;
    for (int i = 0; i < 26; ++i) {
        if (AC[0].vis[i]) {
            AC[AC[0].vis[0]].fail = 0;
            qu.push(AC[0].vis[i]);
        }
    }
    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        for (int i = 0; i < 26; ++i) {
            if (AC[u].vis[i]) {
                AC[AC[u].vis[i]].fail = AC[AC[u].fail].vis[i];
                qu.push(AC[u].vis[i]);
            } else {
                AC[u].vis[i] = AC[AC[u].fail].vis[i];
            }
        }
    }
}

int query (string str) {
    int p = 0, res = 0;
    int len = str.size();
    for (int i = 0; i < len; ++i) {
        p = AC[p].vis[str[i] - 'a'];
        for (int k = p; k && AC[k].endtag != -1; k = AC[k].fail) {
            res += AC[k].endtag;
            AC[k].endtag = -1;
        }
    }
    return res;
}

int main () {
    int n;
    string str;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        build(str);
    }
    AC[0].fail = 0;
    getFail();
    cin >> str;
    cout << query(str) << endl;
    return 0;
}