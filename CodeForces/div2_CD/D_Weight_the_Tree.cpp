#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n;
int h[N], e[2*N], ne[2*N], idx;
int st[N], st1[N];
long long siz[N];

void add(int a, int b){
    e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}

void dfs(int node, int state){
    st[node]=state;
    for(int i=h[node];~i;i=ne[i]){
        if(st[e[i]]!=0) continue;
        dfs(e[i], -state);
    }
}

int main(){
    memset(h,-1,sizeof h);
    cin >> n;
    int black, white;
    for(int i=1;i<=n-1;++i){
        int aa, bb;
        cin >> aa >> bb;
        black=aa, white=bb;
        siz[aa]++, siz[bb]++;
        add(aa, bb), add(bb, aa);
    }
    if(n==2){
        cout << 2 << " " << 2 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }else if(n==4){
        int ok=1;
        int cnt1=0, cnt2=0;
        for(int i=1;i<=n;++i){
            if(siz[i]==1)   cnt1++;
            if(siz[i]==2)   cnt2++;
        }
        if(cnt1==2 && cnt2==2){
            cout << 2 << " " << 4 << endl;
            cout << 1 << " " << 1 << " " << 1 << " " << 1;
            return 0;
        }
    }
    long long res1=0, res2=0, cnt1=0, cnt2=0;
    dfs(black,-1);
    for(int i=1;i<=n;++i){
        if(st[i]==-1)   res1+=siz[i], cnt1++;
        else            res1+=1;
    }
    memcpy(st1,st,sizeof st);
    memset(st,0,sizeof st);
    dfs(white,1);
    for(int i=1;i<=n;++i){
        if(st[i]==1)    res2+=siz[i], cnt2++;
        else            res2+=1;
    }
    if(cnt1>cnt2){
        cout << cnt1 << " " << res1 << endl;
        for(int i=1;i<=n;++i){
            if(st1[i]==-1)  cout << siz[i] << " ";
            else            cout << 1 << " ";
        }
    }else if(cnt1<cnt2){
        cout << cnt2 << " " << res2 << endl;
        for(int i=1;i<=n;++i){
            if(st[i]==1)    cout << siz[i] << " ";
            else            cout << 1 << " ";
        }
    }else{
        if(res1<res2){
            cout << cnt1 << " " << res1 << endl;
            for(int i=1;i<=n;++i){
                if(st[i]==-1)  cout << siz[i] << " ";
                else            cout << 1 << " "; 
            }
        }else{
            cout << cnt2 << " " << res2 << endl;
            for(int i=1;i<=n;++i){
                if(st1[i]==1)    cout << siz[i] << " ";
                else            cout << 1 << " ";
            }
        }
    }
    return 0;
}