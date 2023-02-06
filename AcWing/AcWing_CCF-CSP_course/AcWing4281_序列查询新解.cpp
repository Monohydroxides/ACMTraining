#include <bits/stdc++.h>
using namespace std;

int n, N;
int R;
int a[100010];

long long calc (int l, int r) {
    int lr = l / R, rr = r / R;
    if (lr == rr) {
        return (1ll * r - l + 1) * lr;
    }
    int lx = lr + 1, rx = rr - 1;
    long long ans = 0;
    if (rx >= lx) {
        ans += 1ll * R * (lx + rx) * (rx - lx + 1) / 2;
    }   
    ans += 1ll * (lr * R + R - l) * lr;
    ans += 1ll * (r - rr * R + 1) * rr;
    return ans;
}

int main () {
    cin >> n >> N;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = N;
    R = N / (n + 1);
    long long ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        // cout << a[i] << "\n";
        int l = a[i - 1], r = a[i] - 1;
        int fx = i - 1;
        // cout << l << " " << r << " " << fx << "\n"; 
        if (r / R <= fx || l / R >= fx) {
            ans += abs(1ll * fx * (r - l + 1) - calc(l, r));
            // cout << "nm " << l << " " << r << " " << fx << " " << calc(l, r) << " " << abs(1ll * fx * (r - l + 1) - calc(l, r)) << "\n";
        } else {
            int mid = fx * R;
            // cout << "mid " << mid << "\n";
            ans += 1ll * fx * (mid - l + 1) - calc(l, mid);
            ans += calc(mid + 1, r) - 1ll * fx * (r - mid);
        }
    }
    cout << ans << "\n";
    return 0;
}