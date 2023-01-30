#include <bits/stdc++.h>
using namespace std;

int n, m;
long long numb[2000001];

int main()
{
    int temp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> numb[i];
    }
    for (int j = 1; j <= m; j++)
    {
        cin >> temp;
        cout << numb[temp] << '\n';
    }
    return 0;
}