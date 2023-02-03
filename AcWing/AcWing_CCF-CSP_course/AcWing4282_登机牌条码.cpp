#include <bits/stdc++.h>
using namespace std;

const int mod = 929;

int w, s, k;
string str;
int mode = 1; // 1 big 2 small 3 number
vector<int> coder;
vector<int> cword;

vector<int> gx, dx;

int qmi (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = 1ll * res * a % mod;
        }
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

vector<int> poly_mul (vector<int> a, vector<int> b) { // O(N^2) 多项式乘法，没必要写 O(n log n)
    int sza = a.size(), szb = b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> ans(sza + szb + 1);
    for (int i = 0; i < sza; i++) {
        for (int j = 0; j < szb; j++) {
            ans[i + j] = (ans[i + j] + 1ll * a[i] * b[j] % mod) % mod;
            ans[i + j] = (ans[i + j] + mod) % mod;
        }
    }
    while (ans.size() && ans.back() == 0) ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> poly_mod (vector<int> a, vector<int> b) { // 并不是真的多项式取模，怎么好写怎么来
    if (a.size() < b.size()) { // 取模结束，直接返回
        return a;
    }
    vector<int> bp = b;
    int tm = a[0] / b[0];      // b[0] 一定为 1
    for (int i = 0; i < b.size(); i++) {
        b[i] = 1ll * b[i] * tm % mod;   
    }
    while (b.size() < a.size()) b.push_back(0); // bx 整体乘 tm 后移项和 ax 对齐
    for (int i = 0; i < a.size(); i++) {        // 消去 ax 当前最高位
        a[i] = ((a[i] - b[i]) % mod + mod) % mod;   
    }
    reverse(a.begin(), a.end());
    while (a.size() && a.back() == 0) a.pop_back();
    reverse(a.begin(), a.end());
    return poly_mod(a, bp);
}

void get_gx () {
    gx.push_back(1);                    // gx 的第一项
    gx.push_back(-3);
    for (int i = 2; i <= k; i++) {      // gx 从第二项开始乘
        vector<int> vec;
        vec.push_back(1);
        vec.push_back(-qmi(3, i));
        gx = poly_mul(gx, vec);         // O(N^2) 多项式乘法，没必要写 O(n log n)
    }
}

int main () {
    cin >> w >> s >> str;
    if (s != -1) {
        k = qmi(2, s + 1);
    } else {
        k = 0;
    }
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') { // 根据输入的字符切换模式
            if (mode == 2) {
                coder.push_back(28);
                coder.push_back(28);
                mode = 1;
            } else if (mode == 3) {
                coder.push_back(28);
                mode = 1;
            }
            coder.push_back(str[i] - 'A');
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            if (mode != 2) {
                coder.push_back(27);
                mode = 2;
            }
            coder.push_back(str[i] - 'a');
        } else {
            if (mode != 3) {
                coder.push_back(28);
                mode = 3;
            }
            coder.push_back(str[i] - '0');
        }
    }
    if (coder.size() & 1) { // 奇数补齐
        coder.push_back(29);
    }
    for (int i = 0; i < coder.size(); i += 2) { // 相邻两位构造码元
        cword.push_back(30 * coder[i] + coder[i + 1]);
    }
    while ((cword.size() + 1 + k) % w) {        // 注意计算补齐的方法要带上 k 位校验位
        cword.push_back(900);
    }
    int sz = cword.size() + 1;                  // 码元长度包含自己
    dx.push_back(sz);
    for (auto it : cword) {
        dx.push_back(it);
    }
    for (auto it : dx) {                        // 先输出不带校验部分的答案
        cout << it << "\n";
    }    
    if (s != -1) {
        for (int i = 1; i <= k; i++) {          // 相当于乘以 x^k
            dx.push_back(0);
        }
        get_gx();
        auto rx = poly_mod(dx, gx);             // 并不是真的多项式取模，怎么好写怎么来
        for (auto it : rx) {
            cout << (-it % mod + mod) % mod << "\n";    // 根据公式，需要取反
        }
    }
    return 0;
}
