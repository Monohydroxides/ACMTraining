#include <bits/stdc++.h>
using namespace std;
int n, m;
char p[100010], s[1000010];
int ne[100010];
int main(){
    cin >> n >> p + 1 >> m >> s + 1;
    for(int i = 2, j = 0; i <= n; ++i){
        while(j && p[i] != p[j + 1])    j = ne[j];
        if(p[i] == p[j + 1])    j ++;
        ne[i] = j;
    }
    for(int i = 1, j = 0; i <= m; ++i){
        while(j && p[j + 1] != s[i])    j = ne[j];
        if(p[j + 1] == s[i])    j++;
        if(j == n){
            printf("%d ", i - j);
            j = ne[j];
        }
    }
    return 0;
}
