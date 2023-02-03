#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n;
double a[N];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }
    double avg = sum / (double) n;
    double d2 = 0;
    for (int i = 1; i <= n; i++) {
        d2 += (a[i] - avg) * (a[i] - avg);
    }
    d2 = d2 / (double) n;
    for (int i = 1; i <= n; i++) {
        cout << fixed << setprecision(10) << (a[i] - avg) / sqrt(d2) << '\n';
    }
    return 0;
}