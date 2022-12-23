#include <bits/stdc++.h>
using namespace std;
int n;

int get(int x){
    vector<int> res;
    for(int i = 1; i <= x / i; ++i){
        if(x % i == 0){
            res.push_back(i);
            if(x / i != i){
                res.push_back(x / i);
            }
        }
    }
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
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
