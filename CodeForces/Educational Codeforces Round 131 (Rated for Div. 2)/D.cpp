#include <bits/stdc++.h>
using namespace std;

int b[500010];
int res[500010];
pair<int, pair<int, int> > a[500010];

void work(){
    int n;
    cin >> n;
    map<int, int> st;
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i){
        a[i].second.first = i / (b[i] + 1) + 1;
        a[i].second.second = i / b[i];
        a[i].first = (a[i].second.second - a[i].second.first + 1);
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i){
        for(int j = a[i].second.first; j <= a[i].second.second; ++j){
            if(!st[j]){
                res[i] = j;
                st[j] = 1;
                break; 
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << res[i] << " ";
    }
    cout << endl;
}

int main(){
    int T;
    cin.tie(0);
    cin >> T;
    while(T--)  work();
    return 0;
}