#include <bits/stdc++.h>
using namespace std;

int n;
double i, res;
int a[55];

int main () {
    scanf("%d%lf", &n, &i);
    for (int j = 0; j <= n; j++) {
        scanf("%d", &a[j]);
        res += a[j] * pow(1 + i, -j); 
    }
    printf("%f", res);
    return 0;
}