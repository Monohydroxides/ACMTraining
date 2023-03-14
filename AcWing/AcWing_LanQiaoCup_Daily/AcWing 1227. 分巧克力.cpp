#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 判断是否能从巧克力中切出边长为 x 的正方形
bool check(vector<int>& h, vector<int>& w, int x, int k) {
    int cnt = 0; // 统计切出的正方形个数
    for (int i = 0; i < h.size(); i++) {
        cnt += (h[i] / x) * (w[i] / x); // 每块巧克力可以切出的正方形个数
        if (cnt >= k) return true; // 如果已经达到 k 个，直接返回 true
    }
    return false; // 否则返回 false
}

int main() {
    int n, k; // 输入 n 和 k
    cin >> n >> k;
    vector<int> h(n), w(n); // 存储巧克力的高和宽
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> w[i]; // 输入每块巧克力的高和宽
    }
    int l = 1, r = 1e5; // 二分查找边长的范围
    while (l < r) {
        int mid = (l + r + 1) / 2; // 取中点作为边长
        if (check(h, w, mid, k)) { // 如果能切出边长为 mid 的正方形
            l = mid; // 更新左边界
        } else { // 否则
            r = mid - 1; // 更新右边界
        }
    }
    cout << l << endl; // 输出最大的边长
    return 0;
}