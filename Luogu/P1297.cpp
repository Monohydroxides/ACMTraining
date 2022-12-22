#include<bits/stdc++.h>
using namespace std;

int n, A, B, C, a[10000010];

int main(){
    scanf("%d%d%d%d%d", &n, &A, &B, &C, a + 1);
    for (int i = 2; i <= n; i++)    a[i] = ((long long) a[i - 1] * A + B) % 100000001;
    for (int i = 1; i <= n; i++)    a[i] = a[i] % C + 1;
    double res = 0;
    for(int i = 1; i <= n; ++i){
        if(i == 1){
            res += 1 / (double)(max(a[1], a[n]));
            continue;
        }
        res += 1 / (double)(max(a[i], a[i - 1]));
    }
    printf("%.3lf\n", res);
    return 0;
}