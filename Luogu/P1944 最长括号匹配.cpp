#include<bits/stdc++.h>
using namespace std;

int dp[1000010];

int main()
{
    string str;
    cin >> str;
    str = " " + str;
    int pos = 0, res = 0;
    for(int i = 2; i < str.size(); ++i)
    {
        if(str[i] == ')' || str[i] == ']')
        {
            if((str[i - 1 - dp[i - 1]] == '(' && str[i] == ')')
            || (str[i - 1 - dp[i - 1]] == '[' && str[i] == ']'))
            {
                dp[i] = dp[i - 1] + 2 + dp[i - 2 - dp[i - 1]];
                if(res < dp[i])
                {
                    res = dp[i];
                    pos = i;
                }
            }
        }
    }
    for(int i = pos - res + 1; i <= pos; ++i)
    {
        cout << str[i];
    }
    cout << endl;
    return 0;
}