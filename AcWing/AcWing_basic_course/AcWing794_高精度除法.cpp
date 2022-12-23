#include <bits/stdc++.h>
using namespace std;
vector<int> divf(vector<int>& a, int b, int& r){
    r = 0;
    vector<int> c;
    for(int i = a.size() - 1; i >= 0; --i){
        r = r * 10 + a[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin(), c.end());
    while(c.size() > 1 && c.back() == 0){
        c.pop_back();
    }
    return c;
} 
int main(){
    string a;
    int b;
    int r = 0;
    vector<int> a1, c;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; --i){
        a1.push_back(a[i] - '0');
    }
    c = divf(a1, b, r);
    for(int i = c.size() - 1; i >= 0; --i){
        cout << c[i];
    }
    cout << endl << r << endl;
    return 0;
}
