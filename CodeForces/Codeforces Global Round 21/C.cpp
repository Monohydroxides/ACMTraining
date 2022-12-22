#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 500010;

int T;

int a[N], b[N];

void work(){
    int n, m, k;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    cin >> k;
    for(int i = 1; i <= k; ++i) cin >> b[i];
    vector<pair<int, LL> > a1, b1;
    for(int i = 1; i <= n; ++i){
        LL cnt = 1;
        while(a[i] % m == 0){
            cnt *= m;
            a[i] /= m;
        }
        a1.push_back({a[i], cnt});
    }
    for(int i = 1; i <= k; ++i){
        LL cnt = 1;
        while(b[i] % m == 0){
            cnt *= m;
            b[i] /= m;
        }
        b1.push_back({b[i], cnt});
    }
    int i = 0, j = 0;
    while(i < a1.size() && j < b1.size()){
        if(a1[i].first == b1[j].first){
            if(a1[i].second == b1[j].second){
                a1[i].second = b1[j].second = 0;
                ++i, ++j;
            }else if(a1[i].second > b1[j].second){
                a1[i].second -= b1[j].second;
                b1[j].second = 0;
                ++j;
            }else{
                b1[j].second -= a1[i].second;
                a1[i].second = 0;
                ++i;
            }
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    for(int i = 0; i < a1.size(); ++i){
        if(a1[i].second != 0){
            cout << "NO" << endl;
            return;
        }
    }
    for(int i = 0; i < b1.size(); ++i){
        if(b1[i].second != 0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "Yes" << endl; 
    return;
}

int main(){
    cin.tie(0);
    cin >> T;
    while(T--)  work();
}