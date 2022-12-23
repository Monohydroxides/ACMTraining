#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, m;
char a[N][15];
int f[15][15];

int change(char a[], char b[]){
    int la = strlen(a + 1), lb = strlen(b + 1);
    for(int i = 1; i <= la; ++i)    f[i][0] = i;
    for(int i = 1; i <= lb; ++i)    f[0][i] = i;
    for(int i = 1; i <= la; ++i){
        for(int j = 1; j <= lb; ++j){
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if(a[i] != b[j])    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
            else    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
        }
    }
    return f[la][lb];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i] + 1;
    for(int p = 1; p <= m; ++p){
        char s[15];
        int op, cnt = 0;
        cin >> s + 1 >> op;
        for(int i = 1; i <= n; ++i) if(op >= change(a[i], s))  cnt ++;
        cout << cnt << endl;
    }
    return 0;
}
