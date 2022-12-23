#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n;
PII a[N];

int main(){
    cin >> n;
    int ai, bi;
    for(int i = 1; i <= n; ++i){
        cin >> ai >> bi;
        a[i] = {ai, bi};
    }
    sort(a + 1, a + 1 + n);
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 1; i <= n; ++i){
        if(heap.empty() || a[i].first <= heap.top()) heap.push(a[i].second);
        else{
            heap.pop();
            heap.push(a[i].second);
        }
    }
    cout << heap.size() << endl;
    return 0;
}
