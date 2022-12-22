#include <bits/stdc++.h>
using namespace std;

const int N = 10010;

int n, a[N];
int f[N], g[N];

int main(){
    int res = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i){
    	if(a[i] >= a[i - 1])	f[i] = f[i - 1] + 1;
    	else				f[i] = 1;
    }
    for(int i = n; i >= 1; --i){
    	if(a[i] >= a[i + 1])	g[i] = g[i + 1] + 1;
    	else				g[i] = 1;
    }
    for(int i = 1; i <= n; ++i)	res = max(res, f[i] + g[i] - 1);
    cout << res << endl;
    return 0;
}