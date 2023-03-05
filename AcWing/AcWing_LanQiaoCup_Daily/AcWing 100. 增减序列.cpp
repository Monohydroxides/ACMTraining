#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100010], dif[100010];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], dif[i] = a[i] - a[i - 1];
    long long pos = 0, neg = 0;
    for(int i = 2; i <= n; ++i){
        if(dif[i] < 0){
            neg += -dif[i];
        }else if(dif[i] > 0){
            pos += dif[i];
        }
    }
    long long res = 0, ret = 0;
    if(neg > pos){
        res = neg;
        ret = neg - pos + 1;
    }else if(neg < pos){
        res = pos;
        ret = pos - neg + 1;
    }else{
        res = pos;
        ret = 1;
    }
    cout << res << endl;
    cout << ret << endl;
    return 0;
}