#include <bits/stdc++.h>
using namespace std;
void quicksort(int a[], int l, int r){
    if(l >= r)  return;
    int i = l - 1, j = r + 1, x = a[l + r >> 1];
    while(i < j){
        do  i++; while(a[i] < x);
        do  j--; while(a[j] > x);
        if(i < j)   swap(a[i], a[j]);
    }
    quicksort(a, l, j), quicksort(a, j + 1, r);
}
int main(){
    int n, loc;
    int a[100010];
    scanf("%d %d", &n, &loc);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    printf("%d", a[loc - 1]);
}
