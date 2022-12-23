#include <bits/stdc++.h>
using namespace std;

int n;
struct task {
    int a, b, c, d;
} tsk[50];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tsk[i].a >> tsk[i].b >> tsk[i].c >> tsk[i].d;
    }
    
    return 0;
}