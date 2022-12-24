#include <iostream>
using namespace std;
const int N = 220;

int n, x[N], y[N], dst[N], mx[3] = {-1, -1, -1};

int main() {
    cin >> n >> x[0] >> y[0];
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        dst[i] = (x[0] - x[i]) * (x[0] - x[i]) + (y[0] - y[i]) * (y[0] - y[i]);
    }
    for (int x = 0; x < 3; x++) {
        for (int i = 1 ; i <= n; i++) {
            if (mx[x] == -1 || dst[mx[x]] > dst[i]) mx[x] = i;
        } 
        dst[mx[x]] = 1e7;
        cout << mx[x] << endl;
    }
    return 0;
}
