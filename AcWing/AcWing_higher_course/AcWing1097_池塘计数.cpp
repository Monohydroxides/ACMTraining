#include <bits/stdc++.h>
using namespace std;

int n, m, res;
char g[1001][1001];
int d[8][2]={0,1,0,-1,1,0,-1,0,1,1,-1,-1,-1,1,1,-1};

void fill(int x, int y){
    queue<pair<int, int> > qu;
    qu.push({x,y});
    while(qu.size()){
        auto t = qu.front();
        g[t.first][t.second]='.';
        qu.pop();
        for(int i=0;i<8;++i){
            int nx=t.first+d[i][0];
            int ny=t.second+d[i][1];
            if(nx<1 || ny<1 || nx>n || ny>m)    continue;
            if(g[nx][ny]=='W'){
                qu.push({nx,ny});
                g[nx][ny]='.';
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i)   for(int j=1;j<=m;++j)   cin >> g[i][j];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(g[i][j]=='W'){
                res++;
                fill(i,j);
            }
        }
    }
    cout << res << endl;
    return 0;
}