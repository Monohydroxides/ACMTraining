#include <bits/stdc++.h>

using namespace std;

int a[100010];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    while (q--) {
        int x;
        scanf("%d", &x);
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (a[mid] < x)  l = mid + 1;
            else    r = mid;
        }
        if (a[l] != x) {
            printf("-1 -1\n");
            continue;
        }
        int l1 = l, r1 = n;
        while (l1 + 1 < r1) {
            int mid = l1 + r1 >> 1;
            if (a[mid] <= x)  l1 = mid;
            else    r1 = mid;
        }
        printf("%d %d\n", l, l1);
    }
    return 0;
}

