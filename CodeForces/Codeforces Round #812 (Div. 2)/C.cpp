#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int ans[N];

void work (int n) {
    if (n == 1) {
        ans[0] = 0;
        return;
    }
	if (n == (int) sqrt(n) * (int) sqrt(n)) {
        ans[0] = 0;
        for (int i = 1; i < n; ++i) {
            ans[i] = n - i;
        }
        return;
    }
	if (n == (int) sqrt(n) * (int) sqrt(n) + 1) {
        for (int i = 0; i < n; ++i) {
            ans[i] = n - i - 1; 
        }   
        return;
    } 
	int begin = ((int) sqrt(n) + 1) * ((int) sqrt(n) + 1) - n + 1;
	for (int i = begin; i < n; ++i) {
        ans[i] = n - 1 - (i - begin);
    }
	work(begin);
}

int main(){
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        work(n);
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}