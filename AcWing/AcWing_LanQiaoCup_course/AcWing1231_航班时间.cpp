// Author: pokerface
// https://www.acwing.com/solution/content/13437/

#include<bits/stdc++.h>
using namespace std;
int getTime(void)
{
    int h1,m1,s1,h2,m2,s2,d=0;
    scanf("%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&d);
    int time=d*24*3600+h2*3600+m2*60+s2-(h1*3600+m1*60+s1);
    return time;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        int time1=getTime();
        int time2=getTime();
        int t=(time1+time2)/2;
        printf("%02d:%02d:%02d\n", t/3600, t/60%60, t%60);
    }
    return 0;
}
