#include <stdio.h>
#include "libcs50/cs50.h"

long long power(int a, int b)
{
    int i = 1;
    long long k = a;
    do
    {
        k *= a;
        printf("%lld\n", k);
        i++;
    } while (i < b);
    return k;
}

void main()
{
    long long k = power(10, 15);
    printf("%lld", k);
}