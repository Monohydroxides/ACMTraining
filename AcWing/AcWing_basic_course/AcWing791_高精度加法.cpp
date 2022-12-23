#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> add(vector<int> &a, vector<int> &b){
    if(a.size() < b.size()) return add(b, a);
    vector<int> ans;
    int t = 0;
    for(int i = 0; i < a.size(); ++i){
        t += a[i];
        if(i < b.size())    t += b[i];
        ans.push_back(t % 10);
        t /= 10;
    }
    if(t)   ans.push_back(t);
    return ans;
}
int main(){
    vector<int> ans;
    char a[100010], b[100010];
    scanf("%s %s", a, b);
    vector<int> a1;
    vector<int> b1;
    for(int i = strlen(a) - 1; i >= 0; --i){
        a1.push_back((int)(a[i] - '0'));
    }
    for(int i = strlen(b) - 1; i >= 0; --i){
        b1.push_back((int)(b[i] - '0'));
    }
    ans = add(a1, b1);
    for(int i = ans.size() - 1; i >= 0; --i){
        printf("%d", ans[i]);
    }
    return 0;
}
