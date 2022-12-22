#include <bits/stdc++.h>
using namespace std;

const double inf = 1e14;

int n, m;
pair<int, int> cit[20], che[10];
double dp[(1 << 17)][17];

double dist (int x, int y) {
    pair<int, int> px, py;
    if (x >= n) {
        px = che[x - n];
    } else {
        px = cit[x];
    }
    if (y == -1) {
        return sqrt(pow(px.first, 2) + pow(px.second, 2));
    }
    if (y >= n) {
        py = che[y - n];
    } else {
        py = cit[y];
    }
    return sqrt(pow(px.first - py.first, 2) + pow(px.second - py.second, 2));
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> cit[i].first >> cit[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> che[i].first >> che[i].second;
    }
    int all = n + m;
    memset(dp, 0x42, sizeof dp);
    for (int j = 0; j < all; ++j) {
        dp[1 << j][j] = dist(j, -1) / (double) 1.0;
    }
    for (int state = 1; state < (1 << all); ++state) {
        for (int j = 0; j < all; ++j) {
            if ((state >> j) & 1) {
                double spd = 1.0;
                int stateex = (state ^ (1 << j)) >> n;
                while (stateex) {
                    if (stateex & 1) {
                        spd *= 2;
                    }
                    stateex >>= 1; 
                }
                for (int k = 0; k < all; ++k) {
                    if ((state ^ (1 << j)) >> k & 1) {
                        dp[state][j] = min(dp[state][j], dp[(state ^ (1 << j))][k] + dist(k, j) / spd);
                    }
                }
            }
        }
    }

    double res = inf;
    for (int state = 0; state < (1 << m); ++state) {
        for (int j = 0; j < all; ++j) {
            double spd = 1.0;
            int stateex = state;
            while (stateex) {
                if (stateex & 1) {
                    spd *= 2;
                }
                stateex >>= 1;
            }
            res = min(res, dp[(state << n) | ((1 << n) - 1)][j] + dist(j, -1) / spd);
        }
    }
    cout << fixed << setprecision(9) << res << '\n';
    return 0;
}