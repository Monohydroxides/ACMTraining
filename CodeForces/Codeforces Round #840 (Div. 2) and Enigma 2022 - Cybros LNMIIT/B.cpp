#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct node {
    int id;
    int hp, power;
    bool operator< (const struct node& rhs) const {
        return power < rhs.power;
    }
    bool operator> (const struct node& rhs) const {
        return power > rhs.power;
    }
};

pair<int, int> a[N];

void work () {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].second;
    }
    priority_queue<node, vector<node>, greater<node> > pq;
    for (int i = 1; i <= n; ++i) {
        pq.push({i, a[i].first, a[i].second});
    }
    int sum = 0;
    while (k > 0) {
        sum += k;
        while (pq.size() && pq.top().hp <= sum) {
            pq.pop();
        }
        if (!pq.size()) {
            cout << "YES\n";
            return;
        }
        k -= pq.top().power;
    }
    if (k <= 0) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
}

int main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}