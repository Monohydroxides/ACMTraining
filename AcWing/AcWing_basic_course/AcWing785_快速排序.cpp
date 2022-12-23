#include <bits/stdc++.h>
using namespace std;
void quicksort(int a[], int l, int r){
    if(l >= r){
        return;
    }
    int x = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while(i < j){
        do{
            i++;
        }while(a[i] < x);
        do{
            j--;
        }while(a[j] > x);
        if(i < j){
            swap(a[i], a[j]);
        }
    }
    quicksort(a, l, j), quicksort(a, j + 1, r);
}
int main(){
    int n;
    int a[100010];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    for(int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }

    return 0;
}
