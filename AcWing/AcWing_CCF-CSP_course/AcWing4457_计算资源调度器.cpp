#include <bits/stdc++.h>
using namespace std;

const int N = 1001, inf = 0x3f3f3f3f;

int n, m, g;
int fi, ai, nai, pai, paai, paair;

int node_to_region[N];
int node_task_num[N];

unordered_map< int, vector<int> > app_node;
int avail_region[N];
int paai_node[N];

int find () {
    memset(avail_region, 0, sizeof avail_region);
    memset(paai_node, 0, sizeof paai_node);
    if (pai) {
        vector<int> cur_node = app_node[pai];
        for (int tmp: cur_node) {
            avail_region[node_to_region[tmp]] = 1;
        }
    }
    if (paai) {
        vector<int> cur_node = app_node[paai];
        for (int tmp: cur_node) {
            paai_node[tmp] = 1;
        }
    }
    int ret_node = 0, cur_task = inf;
    for (int i = 1; i <= n; i++) {
        if (((pai && avail_region[node_to_region[i]]) || !pai)
            && ((!paai_node[i] && paai) || !paai)
            && (!nai || (nai && (node_to_region[i] == nai)))
            ) {
            if (cur_task > node_task_num[i]) {
                ret_node = i;
                cur_task = node_task_num[i];
            }
        }
    }
    if (ret_node) {
        return ret_node;
    }
    if (!paair) {
        for (int i = 1; i <= n; i++) {
            if (((pai && avail_region[node_to_region[i]]) || !pai)
                && (!nai || (nai && (node_to_region[i] == nai)))) {
                if (cur_task > node_task_num[i]) {
                    ret_node = i;
                    cur_task = node_task_num[i];
                }
            }
        }
    }
    return ret_node;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> node_to_region[i];
    }   
    cin >> g;
    while (g--) {
        cin >> fi >> ai >> nai >> pai >> paai >> paair;
        vector<int> ans;
        while (fi--) {
            int cur_node = find();
            if (cur_node) {
                node_task_num[cur_node]++;
                app_node[ai].push_back(cur_node); 
            }
            ans.push_back(cur_node);
        }
        for (auto tmp: ans) {
            cout << tmp << " ";
        }
        cout << "\n";
    }
    return 0;
}