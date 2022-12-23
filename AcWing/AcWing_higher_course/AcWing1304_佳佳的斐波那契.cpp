#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 5;

int n, m;

void mul(int c[], int a[], int b[][N]){
    int tmp[N] = {0};
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            tmp[i] = (tmp[i] + (LL)a[j] * b[j][i]) % m;
        }
    }
    memcpy(c, tmp, sizeof tmp);
}

void mul(int c[][N], int a[][N], int b[][N]){
    int tmp[N][N] = {0};
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < N; ++k){
                tmp[i][j] = (tmp[i][j] + (LL)a[i][k] * b[k][j]) % m; 
            }
        }
    }
    memcpy(c, tmp, sizeof tmp);
}

int main(){
    cin >> n >> m;
    int f1[N] = {1, 1, 1, 2, 1};
    int a[N][N] = {
        {0, 1, 0, 2, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 1}
    };
    n--;
    while(n){
        if(n & 1)   mul(f1, f1, a);
        mul(a, a, a);
        n >>= 1;
    }
    cout << f1[4] << endl;
    return 0;
}
