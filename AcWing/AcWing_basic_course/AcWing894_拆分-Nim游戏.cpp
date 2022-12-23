#include <bits/stdc++.h>
using namespace std;

int n;
int f[110];

int sg(int x){
    if(f[x] != -1)  return f[x];
    unordered_set<int> s;
    for(int i = 0; i < x; ++i){
        for(int j = 0; j <= i; ++j){
            s.insert(sg(i) ^ sg(j));
        }
    }
    for(int i = 0;; ++i)    if(!s.count(i)) {f[x] = i; return i;}
}

int main(){
    cin >> n;
    memset(f, -1, sizeof f);
    int res =  0;
    int x;
    while(n--){
        cin >> x;
        res ^= sg(x);
    }
    if(res)    puts("Yes");
    else    puts("No");
    return 0;
}
