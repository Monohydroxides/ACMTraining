#include <bits/stdc++.h>
using namespace std;

int T;

int a[2010];

void work(){
    int n, z;
    cin >> n >> z;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int res = 0;
    for(int i = 1; i <= n; ++i) res = max(res, a[i] | z);
    cout << res << endl;
}

int main(){
    cin.tie(0);
    cin >> T;
    while(T--)  work();
}