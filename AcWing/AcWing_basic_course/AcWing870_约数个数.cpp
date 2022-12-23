#include <bits/stdc++.h>
using namespace std;
int n;
const int mod = 1000000007;
unordered_map<int, int> res;
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        for(int j = 2; j <= a / j; ++j){
            while(a % j == 0){
                res[j]++;
                a /= j;
            }
        }
        if(a > 1)  res[a]++;
    }
    int ans = 1;
    for(auto p : res){ans = (long long)ans * (p.second + 1) % mod;}
    cout << ans << endl;
    return 0;
}
