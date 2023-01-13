#include <bits/stdc++.h>
using namespace std;

int st[100010];

int main () {
    int lines;
    scanf("%d", &lines);
    int x;
    int res1 = 0, res2 = 0;
    while (~scanf("%d", &x)) {
        st[x]++;
    }
    int flg = 0;
    for (int i = 1; i <= 100000; i++) {
        if (st[i]) {
            if (!flg) {
                flg = 1;
            } else {
                if (st[i] == 2) {
                    res2 = i;
                }
            }
        } else {
            if (flg && !res1) {
                res1 = i;
            }
        }
    }
    printf("%d %d\n", res1, res2);
    return 0;
}