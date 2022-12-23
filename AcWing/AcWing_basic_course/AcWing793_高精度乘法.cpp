#include <iostream>
#include <vector>
using namespace std;
vector<int> mul(vector<int> &a, int b){
    int t = 0;
    vector<int> c;
    for(int i = 0; i < a.size() || t; ++i){
        if(i < a.size())    t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    if(t)   c.push_back(t);
    while(c.size() > 1 && c.back() == 0)    c.pop_back();
    return c;
}
int main(){
    string a;
    int b;
    cin >> a >> b;
    vector<int> a1;
    for(int i = a.size() - 1; i >= 0; --i){
        a1.push_back(a[i] - '0');
    }
    vector<int>c = mul(a1, b);
    for(int i = c.size() - 1; i >= 0; --i){
        printf("%d", c[i]);
    }
    return 0;
}
