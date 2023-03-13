#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

int n, T;
int mat[10][10];
int smat[10][10];
int mat4[10][10];
int scan[65];

double mat5[10][10];
int mat6[10][10];

int opt[65][2] = {
    0, 0,
    1, 1,
    1, 2,
    2, 1,
    3, 1,
    2, 2,
    1, 3,
    1, 4,
    2, 3,
    3, 2,
    4, 1,
    5, 1,
    4, 2,
    3, 3,
    2, 4,
    1, 5,
    1, 6,
    2, 5,
    3, 4,
    4, 3,
    5, 2,
    6, 1,
    7, 1,
    6, 2,
    5, 3,
    4, 4,
    3, 5,
    2, 6,
    1, 7,
    1, 8,
    2, 7,
    3, 6,
    4, 5,
    5, 4,
    6, 3,
    7, 2,
    8, 1,
    8, 2,
    7, 3,
    6, 4,
    5, 5,
    4, 6,
    3, 7,
    2, 8,
    3, 8,
    4, 7,
    5, 6,
    6, 5,
    7, 4,
    8, 3,
    8, 4,
    7, 5,
    6, 6,
    5, 7,
    4, 8,
    5, 8,
    6, 7,
    7, 6,
    8, 5,
    8, 6,
    7, 7,
    6, 8,
    7, 8,
    8, 7,
    8, 8
};

void get_scan_matrix () {
    int cur = 1;
    while (cur <= n) {
        smat[opt[cur][0]][opt[cur][1]] = scan[cur];
        cur += 1;
    }
}

void print_scan_matrix () {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cout << smat[i][j] << " ";
        }
        cout << "\n";
    }
}

void print_4_matrix () {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cout << mat4[i][j] << " ";
        }
        cout << "\n";
    }
}

double alpha (int x) {
    if (x == 0) {
        return sqrt(2) / 2.0;
    }
    return 1.0;
}

int main () {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cin >> mat[i][j];
        }
    }
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> scan[i];
    }
    get_scan_matrix();
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            mat4[i][j] = mat[i][j] * smat[i][j];
        }
    }
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            double tmp = 0;
            for (int u = 1; u <= 8; u++) {
                for (int v = 1; v <= 8; v++) {
                    tmp = tmp + alpha(u - 1) * alpha(v - 1) * mat4[u][v] * cos(pi / 8.0 * (i - 0.5) * (u - 1)) * cos(pi / 8.0 * (j - 0.5) * (v - 1));
                }
            }
            tmp = tmp / 4.0;
            mat5[i][j] = tmp;
        }
    }
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            double t = mat5[i][j] + 128.0;
            mat6[i][j] = max(min((int) (t + 0.5), 255), 0);
        }
    }
    if (T == 0) {
        print_scan_matrix();
    } else if (T == 1) {
        print_4_matrix();
    } else {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                cout << mat6[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}