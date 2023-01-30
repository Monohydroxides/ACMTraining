#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int n;
int res = 1;
int resnum = 1;

void dfs(int u, int t, int nw, int p){
    if(res < p || (nw <= resnum && p == res)){
        res = p, resnum = nw;
    }
    if(u > 10)  return;
    for(int i = 1; i <= t; ++i){
        if((LL)nw * primes[u] > n)  break;
        nw *= primes[u];
        dfs(u + 1, i, nw, p * (i + 1));
    }
    return;
}

int main(){
    cin >> n;
    dfs(0, 30, 1, 1);
    cout << resnum << endl;
    return 0;
}