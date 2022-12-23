#include <bits/stdc++.h>
using namespace std;

int n, t;
int efa[2000010];
vector<pair<int, int>> ueq, eq;
unordered_map<int, int> mp;

int find(int x){
    if(x == efa[x]) return x;
    return efa[x] = find(efa[x]);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &t);
        int flag = 1;
        ueq.clear();
        eq.clear();
        mp.clear();
        int ptr = 1;
        for(int j = 1; j <= t; ++j){
            int a, b, e;
            scanf("%d%d%d", &a, &b, &e);
            if(!mp[a])  mp[a] = ptr ++;
            if(!mp[b])  mp[b] = ptr ++;
            a = mp[a], b = mp[b];
            if(e){
                eq.push_back({a, b});
            }else{
                ueq.push_back({a, b});
            }
        }
        for(int j = 0; j <= mp.size(); ++j) efa[j] = j;
        for(int j = 0; j < eq.size(); ++j){
            int pa = find(eq[j].first), pb = find(eq[j].second);
            if(pa == pb)    continue;
            efa[pa] = pb;
        }
        for(int j = 0; j < ueq.size(); ++j){
            int x = ueq[j].first, y = ueq[j].second;
            int px = find(x), py = find(y);
            if(px == py){
                flag = 0;
                break;
            }
        }
        if(flag)    cout << "YES" << endl;
        else        cout << "NO" << endl;
    }
    return 0;
}
