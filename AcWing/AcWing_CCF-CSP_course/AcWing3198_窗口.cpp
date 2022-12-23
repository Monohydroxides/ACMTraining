#include <bits/stdc++.h>
using namespace std;

int n, m;
int ord[15];
struct frame {
    int x1, y1;
    int x2, y2;
} frame[15];

bool check (int x, int y, struct frame p) {
    return x >= p.x1 && x <= p.x2 && y >= p.y1 && y <= p.y2;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        frame[i] = {x1, y1, x2, y2};
        ord[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        int flg = 0;
        for (int j = n; j >= 1; j--) {
            if (check(x, y, frame[ord[j]])) {
                int tmp = ord[j];
                for (int p = j; p < n; p++) {
                    ord[p] = ord[p + 1];
                }
                ord[n] = tmp;
                flg = 1;
                cout << tmp << '\n';
                break;
            }
        }
        if (!flg) {
            cout << "IGNORED\n";
        }
    }
    return 0;
}