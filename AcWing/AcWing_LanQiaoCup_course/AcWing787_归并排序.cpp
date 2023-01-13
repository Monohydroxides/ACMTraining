#include <bits/stdc++.h>
using namespace std;

int a[100010];

void mergesort (int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    int tmp[r - l + 1];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] > a[j]) {
            tmp[k++] = a[j++];
        } else {
            tmp[k++] = a[i++];
        }
    }
    while (i <= mid) {
        tmp[k++] = a[i++];
    }
    while (j <= r) {
        tmp[k++] = a[j++];
    }
    for (int p = l, q = 0; p <= r; p++, q++) {
        a[p] = tmp[q];
    }
}

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    mergesort(1, n);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}