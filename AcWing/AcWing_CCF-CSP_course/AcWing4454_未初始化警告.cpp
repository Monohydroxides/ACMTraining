#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, k, x, y;
int res;
map<int, int> q;

int main(){
    q[0] = 1;
    cin >> n >> k;
    while (k--){
        cin >> x >> y;
        if(!q[y])  res++; 
        q[x] = 1;
    }
    cout << res <<endl;
    return 0;
}