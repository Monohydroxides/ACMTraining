#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 998244353;

int T;
LL a[200010];
LL dif[200010];

void work(){
	int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        dif[i] = a[i] - a[i - 1];
    }
    LL cnt = 0, res = 0;
    for(int i = n; i > 1; --i){
        if(dif[i] < 0){
            cnt += -dif[i];
            dif[i] = 0; 
        }
    }
    dif[1] -= cnt;
    res += cnt;
    if(dif[1] < 0)  res += -dif[1], dif[1] = 0;
    for(int i = 1; i <= n; ++i){
        if(dif[i]){
            res += dif[i];
        }
    }
    cout << res << endl;
	return;
}

int main(){
	cin.tie(0);
	cin >> T;
	while(T--)	work();
	return 0;
}