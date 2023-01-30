#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n;
int res = -0x3f3f3f3f;
int a[N], sum[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        sum[i] += sum[i - 1] + a[i];
        res = max(res, sum[i]);
        if(sum[i] < 0)	sum[i] = 0;
    }
    cout << res << endl;
    return 0;
}