#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, c;
int arr[N];
long long dp[N];
long long sum[N];

int main () {
    cin >> n >> c;
    dp[0] = sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i]; 
    }
    deque<int> deq;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + arr[i];
        while (deq.size() && i - deq.front() >= c) deq.pop_front();
        while (deq.size() && arr[deq.back()] >= arr[i]) deq.pop_back();
        deq.push_back(i);
        if (i >= c) {
            dp[i] = min(dp[i], dp[i - c] + sum[i] - sum[i - c] - arr[deq.front()]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}