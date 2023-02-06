#include <bits/stdc++.h>
using namespace std;

int T;
int tot;
int cnt;
int ces;
int tag[1010];

int main () {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int mi;
        cin >> mi;
        int las = 0;
        for (int j = 1; j <= mi; j++) {
            int x;
            cin >> x;
            if (j == 1) las = x;
            else {
                if (x <= 0) las += x;
                else {
                    if (x < las && !tag[i]) {
                        tag[i] = 1;
                        cnt++;
                        las = x;
                    } else {
                        las = x;
                    }
                }
            }
            if (j == mi) {
                // cout << las << "\n";
                tot += las;
            }
        }
    }
    for (int i = 1; i <= T; i++) {
        if (i == 1) {
            if (tag[i] && tag[i + 1] && tag[T]) {
                ces++;
            }
        } else if (i == T) {
            if (tag[i] && tag[i - 1] && tag[1]) {
                ces++;
            }
        } else {
            if (tag[i - 1] && tag[i] && tag[i + 1]) {
                ces++;
            }
        }
    }
    cout << tot << " " << cnt << " " << ces << "\n";
    return 0;
}