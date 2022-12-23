#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int n, m, g;
int node2region[N];
int fi, ai, nai, pai, paai, paair;
unordered_map< int, vector<int> > region2node;

vector<int> find () {
    vector<int> cur;
    cur = region2node[nai];
    
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        node2region[i] = x;
        region2node[x].push_back(i);
        region2node[0].push_back(i);
    }
    cin >> g;
    while (g--) {
        cin >> fi >> ai >> nai >> pai >> paai >> paair;
        vector<int> node = find();
    }
    return 0;
}