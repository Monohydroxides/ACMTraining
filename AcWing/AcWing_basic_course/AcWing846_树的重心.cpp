#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;
int h[N], e[2 * N], ne[2 * N], idx;
int n;
int ans = N;
bool st[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int x){
    st[x] = true;
    int size = 0, sum = 0;
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if(st[j])   continue;
        int s = dfs(j);
        size = max(size, s);
        sum += s;
    }
    size = max(size, n - sum - 1);
    ans = min(ans, size);
    return sum + 1;
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
