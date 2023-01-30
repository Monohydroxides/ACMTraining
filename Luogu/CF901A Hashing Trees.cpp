#include <bits/stdc++.h>
using namespace std;

int h;
int a[100010];

int main () {
    cin >> h;
    for (int i = 0; i <= h; i++) {
        cin >> a[i];
    }
    int f = 1;
    for (int i = 1; i <= h; i++) {
        if (a[i] > 1 && a[i - 1] > 1) {
            f = 0;
            break;
        }
    }
    if (f) {
        cout << "perfect\n";
        return 0;
    }
    cout << "ambiguous\n";
    cout << 0 << " ";
    int las = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= a[i]; j++) {
            cout << las << " ";
        }
        las += a[i];
    }
    cout << "\n";
    cout << 0 << " ";
    las = 1;
    for (int i = 1; i <= h; i++) {
        if (a[i] > 1 && a[i - 1] > 1) {
            cout << las - 1 << " ";
            for (int j = 1; j < a[i]; j++) {
                cout << las << " ";
            }
        } else {
            for (int j = 1; j <= a[i]; j++) {
                cout << las << " ";
            }
        }
        las += a[i];
    }
    return 0;
}