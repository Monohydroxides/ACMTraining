#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;
const int N = 110;

int n;
double a[N][N];

int gauss(){
    int r, c;
    for(c = 1, r = 1; c <= n; ++c){
        int t = r;
        for(int i = r; i <= n; ++i) if(a[i][c] > a[t][c])   t = i;
        if(fabs(a[t][c]) < eps)   continue;
        for(int j = c; j <= n + 1; ++j) swap(a[t][j], a[r][j]);
        for(int j = n + 1; j >= c; --j) a[r][j] /= a[r][c];
        for(int i = r + 1; i <= n; ++i){
            if(fabs(a[i][c]) > eps){
                for(int j = n + 1; j >= c; --j){
                    a[i][j] -= a[r][j] * a[i][c]; 
                }
            }
        }
        r ++;
    }

    if(r < n + 1){
        for(int i = r; i < n + 1; ++i) if(fabs(a[i][n + 1]) > eps)   return 0;
        return 2;
    }
    for(int i = n; i >= 1; --i){
        for(int j = n; j > i; --j){
            a[i][n + 1] -= a[i][j] * a[j][n + 1];
        }
    }
    return 1;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n + 1; ++j) cin >> a[i][j];
    int res = gauss();
    if(res == 1){
        for(int i = 1; i <= n; ++i){
            if(abs(a[i][n + 1]) < eps)  printf("%.2lf\n", 0.00);
            else    printf("%.2lf\n", a[i][n + 1]);
        }
    } else if(res == 0) puts("No solution");
    else if(res == 2)   puts("Infinite group solutions");
    return 0;
}
