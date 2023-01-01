#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];
pair<int,pair<int,int> > pir[5000010];
int tt = 0, hh = -1;
int d[4][2]={0,1,0,-1,1,0,-1,0};

void print(int x){
    if(pir[x].first!=-1)    print(pir[x].first);
    printf("%d %d\n",pir[x].second.first-1,pir[x].second.second-1);
}

int main(){
    cin >> n;
    for(int i=1;i<=n;++i)   for(int j=1;j<=n;++j)   cin >> a[i][j];
    pir[++hh]={-1,{1,1}};
    a[1][1]=1;
    while(hh>=tt){
        auto t = pir[tt++];
        // cout << t.second.first << " " << t.second.second << endl;
        if(t.second.first==n && t.second.second==n){
            print(tt-1);
            break;
        }
        for(int i=0;i<4;++i){
            int nx=t.second.first+d[i][0], ny=t.second.second+d[i][1];
            if(nx<1 || ny<1 || nx>n || ny>n)    continue;
            if(a[nx][ny])   continue;
            a[nx][ny]=2;
            pir[++hh]={tt-1,{nx,ny}};
        }
    }
    return 0;
}