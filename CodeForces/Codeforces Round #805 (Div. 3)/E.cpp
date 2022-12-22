#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

PII a[200010];
vector<int> arr[200010];
map<int, int> st;

int dfs(int x, int ori, int cnt, int now){
    st[x] = 1;
    int ne = arr[x][0] == now? arr[x][1]: arr[x][0];
    int t = a[ne].first == x? a[ne].second: a[ne].first;
    if(t == ori)    return cnt;
    else            return dfs(t, ori, cnt + 1, ne);
}

void work(){
    int n;
    cin >> n;
    map<int, int> mp;
    st.clear();
    for(int i = 1; i <= n; ++i) arr[i].clear();
    int f = 1;
    for(int i = 1; i <= n; ++i){
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        arr[x].push_back(i), arr[y].push_back(i);
        mp[x]++, mp[y]++;
        if(mp[x] > 2 || mp[y] > 2)  f = 0;
    }
    for(int i = 1; i <= n; ++i){
        if(mp[i] < 2)   f = 0; 
    }
    if(!f){
        cout << "NO" << endl;
        return;
    }
    for(int i = 1; i <= n; ++i){
        if(!st[i] && dfs(i, i, 1, arr[i][0]) & 1){
            // cout << i << endl;
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

int main(){
    int T;
    cin >> T;
    while(T--)  work();
    return 0;
}