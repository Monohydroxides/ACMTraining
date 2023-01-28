#include <bits/stdc++.h>
using namespace std;

int vid;
struct Trie {
    int son[10];
    int tag;
} trie[200010];

void insert (string str) {
    int p = 0;
    for (int i = 0; i < str.size(); i++) {
        int ch = str[i] - '0';
        if (!trie[p].son[ch]) trie[p].son[ch] = ++vid;
        p = trie[p].son[ch];
        trie[p].tag++;
    }
}

int query (string str) {
    int p = 0;
    for (int i = 0; i < str.size(); i++) {
        int ch = str[i] - '0';
        if (!trie[p].son[ch]) return 0;
        p = trie[p].son[ch];
    } 
    return trie[p].tag;
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        int n;
        string str;
        vector<string> strs;
        cin >> n;
        int flg = 0;
        for (int i = 1; i <= n; i++) {    
            cin >> str;
            strs.push_back(str);
            insert(str);
        }
        for (auto it : strs) {
            if (query(it) > 1) {
                flg = 1;
                break;
            }
        }
        if (!flg) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        for (int i = 0; i <= vid; i++) {
            memset(trie[i].son, 0, sizeof(trie[i].son));
            trie[i].tag = 0;
        }
        vid = 0;
    }
    return 0;
}