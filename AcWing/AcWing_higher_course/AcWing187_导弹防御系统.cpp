#include <bits/stdc++.h>
using namespace std;

int n;
int a[55];
int up[55],dn[55];

bool dfs(int dpt, int u, int sup, int sdn){
    if(sup+sdn>dpt) return false;
    if(u>n) return true;
    bool ok=false;
    for(int i=1;i<=sup;++i){
        if(a[u]>up[i]){
            int t=up[i];
            up[i]=a[u];
            if(dfs(dpt,u+1,sup,sdn))    return true;
            up[i]=t;
            ok=1;
            break;
        }
    }
    if(!ok){
        up[sup+1]=a[u];
        if(dfs(dpt,u+1,sup+1,sdn)) return true;
    }

    ok=false;
    for(int i=1;i<=sdn;++i){
        if(a[u]<dn[i]){
            int t=dn[i];
            dn[i]=a[u];
            if(dfs(dpt,u+1,sup,sdn))    return true;
            dn[i]=t;
            ok=1;
            break;
        }
    }
    if(!ok){
        dn[sdn+1]=a[u];
        if(dfs(dpt,u+1,sup,sdn+1))  return true;
    }
    return false;
}

int main(){
    while(cin >> n, n){
        for(int i=1;i<=n;++i)   cin >> a[i];  
        int dpt=0, sup=0, sdn=0;
        while(!dfs(dpt,1,sup,sdn))  dpt++;
        cout << dpt << endl;
    }
    return 0;
}
