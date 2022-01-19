//find gcd 
#include <stdio.h>

int gcd(int m, int n){
    if (n != 0)
        return (n, n % m);
    else 
        return m;
}

int main(void){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("GCD: %d\n", gcd(x, y));
    return 0;
}