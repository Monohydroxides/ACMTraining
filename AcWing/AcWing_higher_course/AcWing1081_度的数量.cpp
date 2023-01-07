#include <bits/stdc++.h>
using namespace std;

const int N = 35;

int n, m;
int K, B;
int Comb[N + 1][N + 1];

void init () {
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= i; j++)
            if (j == 0) Comb[i][j] = 1;
            else Comb[i][j] = Comb[i - 1][j - 1] + Comb[i - 1][j];
}

int work (int x) {
    if (!x) return 0;
    vector<int> nums;
    while (x) {
        nums.push_back(x % B);
        x /= B;
    }
    int las = 0, res = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
        int x = nums[i];
        if (x) {
            res += Comb[i][K - las];
            if (x > 1) {
                if (K - las - 1 >= 0) res += Comb[i][K - las - 1];
                break;
            } else {
                las++;
                if (las > K) break;
            }
        }
        if (i == 0 && las == K) res++;
    }
    return res;
}

int main () { 
    init();
    cin >> n >> m >> K >> B;
    cout << work(m) - work(n - 1) << '\n';  
    return 0;
}