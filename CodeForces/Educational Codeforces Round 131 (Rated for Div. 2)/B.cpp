#include <bits/stdc++.h>
using namespace std;

void work(){
    int n;
    cin >> n;
    vector<int> res;
    map<int, int> mp;
    for(int i = 1; i <= n; ++i){
        if(!mp[i]){
            res.push_back(i);
            mp[i] = 1;
            int j = i * 2;
            while(j <= n){
                res.push_back(j);
                mp[j] = 1;
                j *= 2;
            }
        }
    }
    cout << 2 << endl;
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    return;
}

int main(){
    int T;
    cin >> T;
    while(T--)  work();
    return 0;
}