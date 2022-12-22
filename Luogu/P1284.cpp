#include <bits/stdc++.h>
using namespace std;

int n;
double res = -1;
int a[45];
int sum;
int dp[810][810];

double calc (int l1, int l2, int l3) {
    double p = (double) (l1 + l2 + l3) / 2.0;
    return sqrt(p * (p - l1) * (p - l2) * (p - l3));
}   

int check (int l1, int l2, int l3) {
    if (l1 + l2 <= l3 || l2 + l3 <= l1 || l1 + l3 <= l2)    return 0;
    return 1; 
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = sum / 2; j >= 0; --j) {
            for (int k = sum / 2; k >= 0; --k) {
                if (j - a[i] >= 0 && dp[j - a[i]][k])   dp[j][k] = 1;
                if (k - a[i] >= 0 && dp[j][k - a[i]])   dp[j][k] = 1;
            }
        }
    }
    for (int i = sum / 2; i >= 0; --i) {
        for (int j = sum / 2; j >= 0; --j) {
            if (!dp[i][j])   continue;
            if (!check(i, j, sum - i - j))  continue;
            res = max(res, calc(i, j, sum - i - j));
        }
    }
    if (res == -1) {
        cout << res << '\n';
        return 0;
    }
    cout << (int) (res * 100) << '\n';
    return 0;
}