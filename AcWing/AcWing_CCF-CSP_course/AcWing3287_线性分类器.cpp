#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
int n, m;
int a[N], b[N];
char c[N];
int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    while (m--) {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        int x, y, z;
        cin >> x >> y >> z;
        for(int i = 0; i < n; i++) {
            if (c[i] == 'A') {
                if (x + y * a[i] + z * b[i] > 0) cnt1++;
                if (x + y * a[i] + z * b[i] < 0) cnt3++;
            } else { 
                if (x + y * a[i] + z * b[i] < 0) cnt2++;
                if (x + y * a[i] + z * b[i] > 0) cnt4++;
            }
        }
        if (cnt1 + cnt2 == n || cnt3 + cnt4 == n) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
