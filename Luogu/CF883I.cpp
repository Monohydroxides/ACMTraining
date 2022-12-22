#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, k;
int arr[N];
int dp[N];

bool check(int v){
    memset(dp, 0, sizeof dp);
	int l = 1;
	dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        while (arr[i] - arr[l] > v) l++;
        int r = i - k + 1;
        for (int j = l; j <= r; ++j) {
            if (dp[j - 1]) {
                dp[i] = 1;
                break;
            } else {
                l++;
            }
        }
    }
	return dp[n];
}

int main () {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    int l = 0, r = arr[n] - arr[1];
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid - 1;
        else    l = mid + 1;
    }
    if (check(l)) {
        cout << l << '\n';
    } else {
        cout << l + 1 << '\n';
    }
    return 0;
}