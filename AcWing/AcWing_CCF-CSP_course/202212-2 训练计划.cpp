#include <bits/stdc++.h>
using namespace std;

int n, m;
int pi[110], ti[110];
int st[110], outd[110], las[110];
vector<int> to[110];

int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> pi[i];
        to[pi[i]].push_back(i);
        outd[pi[i]]++;
        if (pi[i] == 0) {
            st[i] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> ti[i];
    }
    int flg = 0;
    for (int i = 1; i <= m; i++) {
        if (!st[i]) {
            st[i] = st[pi[i]] + ti[pi[i]];
            if (st[i] + ti[i] > n) {
                flg = 1;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << st[i] << " ";
    }
    cout << "\n";
    if (flg) {
        return 0;
    }

    vector<int> tp;
    queue<int> qu;
    for (int i = 1; i <= m; i++) {
        if (!outd[i]) {
            qu.push(i);
        }
    }
    while (qu.size()) {
        int cur = qu.front();
        tp.push_back(cur);
        qu.pop();
        if (pi[cur] != 0) {
            outd[pi[cur]]--;
            if (outd[pi[cur]] == 0) {
                qu.push(pi[cur]);
            }
        }    
    }
    for (int i = 1; i <= m; i++) {
        las[i] = n - ti[i] + 1;
    }
    for (auto it : tp) {
        // cout << "it " << it << "\n";
        for (auto sp : to[it]) {
            // cout << sp << " " << it << "\n";
            las[it] = min(las[it], las[sp] - ti[it]);
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << las[i] << " ";
    }
    cout << "\n";
    return 0;
}