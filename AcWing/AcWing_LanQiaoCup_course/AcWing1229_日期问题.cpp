// Author: QAQ_ning
// https://www.acwing.com/solution/content/45600/
#include <cstdio>
#include <iostream>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check_valid(int year, int month, int day)
{
    if (month == 0 || month > 12) return false;
    if (day == 0) return false;
    if (month != 2)
    {
        if (day > days[month]) return false;
    }
    else
    {
        int leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
        if (day > days[month] + leap) return false;
    }

    return true;
}

int main()
{
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);

    for (int date = 19600101; date <= 20591231; date ++ )
    {
        int year = date / 10000, month = date % 10000 / 100, day = date % 100;
        if (check_valid(year, month, day))
        {
            if ((year % 100 == a && month == b && day == c) ||  // 年/月/日
                (month == a && day == b && year % 100 == c) ||  // 月/日/年
                (day == a && month == b && year % 100 == c) )   //月/日/年
                printf("%d-%02d-%02d\n", year, month, day);  //补前导0
        }
    }

    return 0;
}
