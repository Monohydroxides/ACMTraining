#include <bits/stdc++.h>
using namespace std;

int n;
int ai[10010], bi[10010], ci[10010];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ci[i];
    }
    ai[1] = 400, bi[1] = 600;
    for (int i = 2; i <= n; i++) {
        double cur = (double) ci[i] * 6.0 / (double) 5.0;
        int score = (cur * 10 + 5) / 10;
        for (int j = 0; 3 * j <= score; j++) {
            if ((score - 3 * j) % 2 == 0 && (score - 3 * j) / 2 <= 600) {
                ai[i] = j;
                bi[i] = (score - 3 * j) / 2;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ai[i] << " " << bi[i] << '\n';
    }
    return 0;
}