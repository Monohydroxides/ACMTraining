#include <bits/stdc++.h>
using namespace std;
int n;

void get(int x){
    vector<pair<int, int>> res;
    for(int i = 2; i <= x / i; ++i){
        if(x % i == 0){
            int s = 0;
            while(x % i == 0)   x /= i, s++;
            res.push_back({i, s});
        }
    }
    if(x != 1)  res.push_back({x, 1});
    for(int i = 0; i < res.size(); ++i){
        cout << res[i].first << " " << res[i].second << endl;
    }
    cout << endl;
}

int main(){
    cin >> n;
    int a;
    while(n--){
        cin >> a;
        get(a);
    }
    return 0;
}
