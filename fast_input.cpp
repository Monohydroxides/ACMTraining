#include<bits/stdc++.h>
using namespace std;

template<typename T> 
void read (T &x) {
    x = 0;
    int f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c=='-') 
            f = -1;
        c=getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    x *= f;
}

template<typename T, typename ... Args>
void read (T &x, Args& ... y) {
    read(x);
    read(y...);
}

int main () {
  int a;
  read(a); // 读入一个数
  int b;
  long long c;
  read(b, c); // 读入两个数，类型不同也可以
  char str[10];
  scanf("%s", str); // 不影响 scanf/cin 使用
  cout << a << " " << b << " " << c << " " << str << '\n';
  return 0;
}