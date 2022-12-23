#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n;
bool a[N][N];

int gauss(){
    int r, c;
    for(r = 1, c = 1; c <= n; ++c){
        int t = 1;
        for(t = r; t <= n; ++t) if(a[t][c]) break;
        if(!a[t][c])    continue;
        for(int j = c; j <= n + 1; ++j) swap(a[t][j], a[r][j]);
        for(int i = r + 1; i <= n; ++i) if(a[i][c]) for(int j = c; j <= n + 1; ++j) a[i][j] ^= a[r][j];
        r++;
    }
    if(r < n + 1){
        for(int i = r; i <= n; ++i) if(a[i][n + 1]) return 0;
        return 2;
    }
    for(int i = n; i >= 1; --i) for(int j = n; j > i; --j)  if(a[i][j]) a[i][n + 1] = a[i][n + 1] ^ a[j][n + 1];
    return 1;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n + 1; ++j) cin >> a[i][j];
    int res = gauss();
    if(res == 0)    puts("No solution");
    else if(res == 2)   puts("Multiple sets of solutions");
    else    for(int i = 1; i <= n; ++i) cout << a[i][n + 1] << endl;
    return 0;
}
