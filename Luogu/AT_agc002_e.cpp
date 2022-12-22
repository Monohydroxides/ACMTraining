#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    for (int i = 1; i <= n; ++i) {
        if (i + 1 > a[i + 1]) {
            int j = 0;
            while(i == a[i + 1 + j]) {
                ++j;
            }
            if (((a[i] - i) & 1) || (j & 1)) {
                cout << "First" << endl;
            } else {
                puts("Second");
            }
            return 0;
        }
    }
    return 0;
}