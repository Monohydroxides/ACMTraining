#include <bits/stdc++.h>
using namespace std;

void work(){
    int n, k;
    cin >> n >> k;
    map<int, int> mp, las;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        if(!mp[x]){
            mp[x] = i;
        }
        las[x] = i;
    }
    for(int i = 1; i <= k; ++i){
        int a, b;
        cin >> a >> b;
        if(mp[a] != 0 && las[b] != 0 && mp[a] < las[b]){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--)  work();
    return 0;
}