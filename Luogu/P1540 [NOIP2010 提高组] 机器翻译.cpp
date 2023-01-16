#include <bits/stdc++.h>
using namespace std;

int m, n, ans;
int book[1001];
queue<int> q;

int main()
{
    int temp;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        if (book[temp])
        {
            continue;
        }
        if (q.size() >= m)
        {
            book[q.front()] = 0;
            q.pop();
        }
        q.push(temp);
        ans++;
        book[q.back()] = 1;
    }
    cout << ans;
    return 0;
}