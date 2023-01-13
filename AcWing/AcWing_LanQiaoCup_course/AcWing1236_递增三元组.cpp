#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

long long n;
long long a[N], b[N], c[N];
long long las[N];
long long rb[N];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    sort(c + 1, c + 1 + n);
    for (int j = 1; j <= n; j++) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (b[j] < c[mid]) r = mid;
            else l = mid + 1;
        }
        if (c[l] > b[j]) rb[j] = l;
        else rb[j] = n + 1;
    }
    for (int i = n; i >= 1; i--) {
        las[i] = n - rb[i] + 1 + las[i + 1];
    }
    long long res = 0;
    int j = 1;
    for (int i = 1; i <= n; i++) {
        while (j <= n && b[j] <= a[i]) j++;
        if (b[j] > a[i]) {
            res += las[j];
        }
    }
    cout << res << '\n';
    return 0;
}