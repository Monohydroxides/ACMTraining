#include <bits/stdc++.h>
using namespace std;

int T;

int n;

int query(int l, int r){
    cout << "? " << l << " " << r << endl;
    int cnt = 0;
    for(int i = l; i <= r; ++i){
        int x;
        cin >> x;
        if(x >= l && x <= r)    cnt++;
    }
    if(cnt & 1) return 1;
    else        return 0;
}

int work(int l, int r){
    if(l == r)  return l;
    int mid = l + r >> 1;
    if(query(l, mid)){
        return work(l, mid);
    }else{
        return work(mid + 1, r);
    }
}

int main(){
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        int ans = work(1, n);
        cout << "! " << ans << endl;
    }
    return 0;
}