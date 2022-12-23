#include <stdio.h>
#include <math.h>
double ect = 1e-8;
double sqrt_3(double n){
    double l = -10000, r = 10000;
    double mid = (r + l) / 2;
    while(abs(mid * mid * mid - n) >= ect){
        mid = (r + l) / 2;
        if(mid * mid * mid >= n){
            r = mid;
        } else {
            l = mid;
        }
    }
    return mid;
}
int main(){
    double n;
    scanf("%lf", &n);
    printf("%.6lf", sqrt_3(n));
    return 0;
}
