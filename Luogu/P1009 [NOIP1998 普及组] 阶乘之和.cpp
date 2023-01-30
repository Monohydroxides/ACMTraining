#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> f[55], s[55];

vector<int> mul(vector<int> a, int b){
    vector<int> res;
    int t = 0;
    for(int i = 0; i < a.size(); ++i){
        t += a[i] * b;
        res.push_back(t % 10);
        t /= 10;
    }
    while(t){
        res.push_back(t % 10);
        t /= 10;
    }
    return res;
}

vector<int> add(vector<int> a, vector<int> b){
    int sza = a.size(), szb = b.size();
    if(sza < szb)   return add(b, a);
    vector<int> res;
    int t = 0;
    for(int i = 0; i < sza; ++i){
        t += a[i];
        if(i < szb) t += b[i];
        res.push_back(t % 10);
        t /= 10;
    }
    if(t)   res.push_back(t);
    return res;
}

void init(){
    f[1].push_back(1);
    s[1].push_back(1);
    for(int i = 2; i <= 50; ++i){
        f[i] = mul(f[i - 1], i);
        s[i] = add(s[i - 1], f[i]);
    }
}

int main(){
    init();
    cin >> n;
    reverse(s[n].begin(), s[n].end());
    for(int i = 0; i < s[n].size(); ++i){
        cout << s[n][i];
    }
    cout << endl;
    return 0;
}