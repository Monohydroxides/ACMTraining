#include <bits/stdc++.h>
using namespace std;

int gauss (vector< vector<int> >& mat) {
    int n = mat.size();
    int row, col;
    int res = 0;
    for (col = 0, row = 0; col < n; col++) {
        int cur = row;
        if (!mat[cur][col]) {
            for (int i = row + 1; i < n; i++) {
                if (mat[i][col]) {
                    cur = i;
                    break;
                }
            }
        }
        if (!mat[cur][col]) {
            continue;
        }
        if (cur != row) {
            for (int i = col; i <= n; i++) {
                swap(mat[row][i], mat[cur][i]);
            }
        }
        for (int i = row + 1; i < n; i++) {
            if (mat[i][col]) {
                for (int j = n; j >= col; j--) {
                    mat[i][j] ^= mat[row][j];
                }
            }
        }
        row++;
        res++;
    }
    if (row <= n) {
        for (int j = row; j < n; j++) {
            if (mat[j][n]) {
                return -1;
            }
        }
        return n - res;
    }
    return 0;
}

void work () {
    int n;
    cin >> n;
    vector< vector<int> > mat(n, vector<int> (n + 1, 0));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mat[i][n] ^= x;
        mat[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mat[i][n] ^= x;
    }
    int x, y;
    while (cin >> x >> y, (x || y)) {
        x--, y--;
        mat[y][x] = 1;
    }
    int ret = gauss(mat);
    if (ret == -1) {
        cout << "Oh,it's impossible~!!\n";
    }
    cout << (int) pow(2, ret) << '\n';
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}