#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int mod = 1e9 + 7;

int c[2010][2010];

int main(){
    for(int i = 0; i <= 2000; ++i){
        for(int j = 0; j <= i; ++j){
            if(j == 0){
                c[i][j] = 1;
                continue;
            }
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    int n;
    cin >> n;
    int a, b;
    while(n--){
        cin >> a >> b;
        cout << c[a][b] << endl;
    }
    return 0;
}
