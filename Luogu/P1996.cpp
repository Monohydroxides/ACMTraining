#include <bits/stdc++.h>
using namespace std;

int total, out;
queue<int> q;

int main()
{
    cin >> total >> out;
    int i;
    for (i = 1; i <= total; i++)
    {
        q.push(i);
    }
    i = 1;
    while (!q.empty())
    {
        if (i == out)
        {
            cout << q.front() << ' ';
            q.pop();
            i = 1;
        }
        else
        {
            i++;
            q.push(q.front());
            q.pop();
        }
    }
    return 0;
}