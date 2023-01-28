#include <bits/stdc++.h>
using namespace std;

// mt19937 rnd(time(0));

int main () {
    srand(time(0));
    puts("100000 30");
    for (int i = 1; i <= 100000; i++) {
        printf("%c", (rand() % 26 + 'a'));
    }
    puts("");
    return 0;
}