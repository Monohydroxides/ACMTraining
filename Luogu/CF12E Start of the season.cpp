#include <bits/stdc++.h>
using namespace std;

int n;
int a[1010][1010];

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
	        a[i][j] = (i + j) % (n - 1) + 1;
        }
    }
    for (int i = 0; i < n; ++ i) {
        a[i][n - 1] = a[n - 1][i] = a[i][i];
        a[i][i] = 0;
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            cout << a[i][j] << " ";
        }
  	  	cout << "\n";
    }
    return 0;
}
