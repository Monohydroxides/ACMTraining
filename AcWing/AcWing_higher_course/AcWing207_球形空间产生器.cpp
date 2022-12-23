#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<double>> point, mat;
double eps = 1e-6;

int gauss(){
    int c, r;
    for(c = 0, r = 0; c < n; ++c){
        int t = r;
        for(int i = r; i < n; ++i){
            if(fabs(mat[i][c]) > fabs(mat[t][c])){
                t = i;
            }
        }
        if(fabs(mat[t][c]) < eps) continue;
        for(int i = c; i <= n; ++i) swap(mat[t][i], mat[r][i]);
        for(int i = n; i >= c; --i) mat[r][i] /= mat[r][c];
        for(int i = r + 1; i < n; ++i){
            if(fabs(mat[i][c]) > eps){
                for(int j = n; j >= c; --j){
                    mat[i][j] -= mat[r][j] * mat[i][c];
                }
            }
        }
        ++r;
    }
    if(r < n){
        for(int i = r; i < n; ++i){
            if(fabs(mat[i][n]) > eps){
                return 2;
            }
        }
        return 1;
    }
    for(int i = n - 1; i >= 0; --i){
        for(int j = i + 1; j < n; ++j){
            mat[i][n] -= mat[i][j] * mat[j][n]; 
        }
    }
    return 0;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n + 1; ++i){
        vector<double> tmp;
        for(int j = 1; j <= n; ++j){
            double x;
            cin >> x;
            tmp.push_back(x);
        }
        point.push_back(tmp);
    }
    for(int i = 1; i <= n; ++i){
        vector<double> tmp;
        double ret = 0;
        for(int j = 0; j < n; ++j){
            tmp.push_back(2 * (point[0][j] - point[i][j]));
            ret += (point[i][j] + point[0][j]) * (point[i][j] - point[0][j]);
        }
        tmp.push_back(ret);
        mat.push_back(tmp);
    }
    gauss();
    for(int i = 0; i < n; ++i){
        printf("%.3lf ", -mat[i][n]);
    }
    return 0;
}
