#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int a[257];
int main(){
    cin >> n >> m >> l;
    int temp;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> temp, ++a[temp];
    for(int i = 0; i < l; ++i)  cout << a[i] << " ";
    return 0;
}