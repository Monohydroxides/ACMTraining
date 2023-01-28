#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int main () {
	int T;
    cin >> T;
	while (T--) {
        cin >> n;
	    for (int i = 1; i <= n; i++) cin >> a[i];
        if (n & 1) {
            if (a[1] + a[2]) {
                cout << -a[3] << " " << -a[3] << " " << a[1] + a[2] << " ";
            } else if (a[2] + a[3]) {
                cout << a[2] + a[3] << " " << -a[1] << " " << -a[1] << " ";
            } else {
                cout << -a[2] << " " << a[1] + a[3] << " " << -a[2] << " ";
            }
            for (int i = 4; i <= n; i += 2) {
                cout << -a[i + 1] << " " << a[i] << " ";
            }
        } else {
            for (int i = 1; i <= n; i += 2) {
                cout << -a[i + 1] << " " << a[i] << " ";
            }
        }
        cout << '\n';
    }
	return 0;
}