#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int h[20], e[500], ne[500], idx;
long long dp[1 << 19][20];


void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}


int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    for(int i = 1; i <= n; ++i)
    {
        dp[1 << (i - 1)][i] = 1;
    }
    long long res = 0;
    for(int st = 0; st < (1 << n); ++st)
    {
        for(int i = 1; i <= n; ++i)
        {
            if(!dp[st][i])  continue;
            for(int j = h[i]; ~j; j = ne[j])
            {
                int v = e[j];
                if((st & (-st)) > (1 << (v - 1)))
                {
                    continue;
                }
                if(st & (1 << (v - 1)))
                {
                    if((st & (-st)) == (1 << (v - 1)))
                    {
                        res += dp[st][i];
                    }
                }
                else
                {
                    dp[st | (1 << (v - 1))][v] += dp[st][i];
                }
            }
        }
    }
    cout << (res - m) / 2 << endl;
    return 0;
}