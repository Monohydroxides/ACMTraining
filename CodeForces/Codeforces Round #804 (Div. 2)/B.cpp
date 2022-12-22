#include <bits/stdc++.h>
using namespace std;

int T;

int f[55][55];

void work(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}

void draw(int x, int y, int t){
    if(t){
        f[x][y] = 1, f[x + 1][y] = 0, f[x][y + 1] = 0, f[x + 1][y + 1] = 1;
    }else{
        f[x][y] = 0, f[x + 1][y] = 1, f[x][y + 1] = 1, f[x + 1][y + 1] = 0;
    }
}

int main(){
    cin >> T;
    int t = 0;
    for(int i = 1; i <= 50; i += 2){
        for(int j = 1; j <= 50; j += 2){
            draw(i, j, t);
            t ^= 1;
        }
    }
    while(T--)  work();
    return 0;
}