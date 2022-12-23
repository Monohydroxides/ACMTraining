#include <bits/stdc++.h>
using namespace std;

const int N = 14;
const double INF = 1e20;

int A, B, C, D;
double f[N][N][N][N][5][5];

double dp(int a, int b, int c, int d, int x, int y){
    double& v = f[a][b][c][d][x][y];
    if(v >= 0)  return v;
    int al = a + (x == 0) + (y == 0);
    int bl = b + (x == 1) + (y == 1);
    int cl = c + (x == 2) + (y == 2);
    int dl = d + (x == 3) + (y == 3);
    if(al >= A && bl >= B && cl >= C && dl >= D)    return v = 0.0;
    int sum = 54 - a - b - c - d - (x != 4) - (y != 4);
    if(sum <= 0) return v = INF;
    v = 1;
    if(a < 13)  v += (13.0 - a) / sum * dp(a + 1, b, c, d, x, y);
    if(b < 13)  v += (13.0 - b) / sum * dp(a, b + 1, c, d, x, y);
    if(c < 13)  v += (13.0 - c) / sum * dp(a, b, c + 1, d, x, y);
    if(d < 13)  v += (13.0 - d) / sum * dp(a, b, c, d + 1, x, y);
    if(x == 4){
        double t = INF;
        for(int i = 0; i < 4; ++i)  t = min(t, 1.0 / sum * dp(a, b, c, d, i, y));
        v += t;
    }
    if(y == 4){
        double t = INF;
        for(int i = 0; i < 4; ++i)  t = min(t, 1.0 / sum * dp(a, b, c, d, x, i));
        v += t;
    }
    return v;
}

int main(){
    cin >> A >> B >> C >> D;
    memset(f, -1, sizeof f);
    double res = dp(0, 0, 0, 0, 4, 4);
    if(res > INF / 2)  cout << "-1.000" << endl;
    else                printf("%.3lf\n", res);
    return 0;
}
