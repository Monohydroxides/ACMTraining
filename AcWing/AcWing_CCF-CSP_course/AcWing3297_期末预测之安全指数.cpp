#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    int res = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int a, b;
        cin >> a >> b;
        res += a * b;
    }
    cout << max(res, 0) << endl;
    return 0;
}