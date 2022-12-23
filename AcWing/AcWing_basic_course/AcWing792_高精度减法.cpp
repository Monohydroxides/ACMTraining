#include <iostream>
#include <vector>
using namespace std;
bool cmp(vector<int>&a, vector<int>&b){
    if(a.size() != b.size())    return a.size() > b.size();
    for(int i = a.size() - 1; i >= 0; --i){
        if(a[i] != b[i]){
            return a[i] > b[i];
        }
    }
    return true;
}
vector<int> sub(vector<int> &a, vector<int> &b){
    int t = 0;
    vector<int> c;
    for(int i = 0; i < a.size(); ++i){
        int n = a[i] - t;
        if(i < b.size())    n -= b[i];
        c.push_back((n + 10) % 10);
        if(n < 0)   t = 1;
        else t = 0;
    }
    while(c.size() > 1 && c.back() == 0)    c.pop_back();
    return c;
}
int main(){
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for(int i = a.size() - 1; i >= 0; --i){
        A.push_back(a[i] - '0');
    }
    for(int j = b.size() - 1; j >= 0; --j){
        B.push_back(b[j] - '0');
    }
    if(cmp(A, B)){
        vector<int> C = sub(A, B);
        for(int i = C.size() - 1; i >= 0; --i){
            printf("%d", C[i]);
        }
    } else {
        vector<int> C =sub(B, A);
        printf("-");
        for(int i = C.size() - 1; i >= 0; --i){
            printf("%d", C[i]);
        }
    }
    return 0;
}
