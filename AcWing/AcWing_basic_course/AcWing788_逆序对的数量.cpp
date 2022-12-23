#include <bits/stdc++.h>
long long cnt = 0;
void merge_sort(long long q[], long long l, long long r)
{
    if (l >= r) return;

    long long mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    long long k = 0, i = l, j = mid + 1, tmp[r - l + 1];
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else cnt += mid - i + 1, tmp[k ++ ] = q[j ++ ];

    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}

int main(){
    int n;
    scanf("%d", &n);
    long long a[100010];
    for(int i = 0; i < n; ++i){
        scanf("%lld", &a[i]);
    }
    merge_sort(a, 0, n - 1);
    printf("%lld", cnt);
    return 0;
}
