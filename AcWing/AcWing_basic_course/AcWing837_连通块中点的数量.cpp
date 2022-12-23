#include <bits/stdc++.h>
using namespace std;

int n, m;
int s[100010], cnt[100010];

int find(int x){
    if(x != s[x])   s[x] = find(s[x]);
    return s[x];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        s[i] = i;
        cnt[i] = 1;
    }
    string opt;
    int a, b;
    while(m--){
        cin >> opt;
        if(opt == "C"){
            cin >> a >> b;
            if(find(a) == find(b))  continue;
            cnt[find(b)] += cnt[find(a)];
            s[find(a)] = find(b);
        } else if(opt == "Q1"){
            cin >> a >> b;
            if(find(a) == find(b)){
                cout << "Yes" << endl;
            } else cout << "No" << endl;
        } else {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}
