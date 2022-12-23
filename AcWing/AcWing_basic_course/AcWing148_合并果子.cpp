#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> a;

int main(){
    cin >> n;
    int t;
    for(int i = 1; i <= n; ++i) cin >> t, a.push(t);
    int res = 0;
    while(a.size() > 1){
        int p = a.top();a.pop();
        int q = a.top();a.pop();
        // cout << p << " " << q << endl;
        res += p + q;
        a.push(p + q);
    }
    cout << res << endl;
    return 0;
}
