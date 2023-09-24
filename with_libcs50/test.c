#include <stdio.h>
#include "libcs50/cs50.h"
// gcc test.c -o bin/test libcs50/cs50.c && ./bin/test

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
    // long long k = power(10, 15);
    int turn = 1;
    char player = turn % 2 == 0 ? 'X' : 'O';
    char my_char = get_char("%c: ", player);
}