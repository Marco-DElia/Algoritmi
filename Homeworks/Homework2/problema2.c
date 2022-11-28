#include <stdio.h>

#define MAXN 100

int f (int n, int memo[])
{
    if (n == 1) return 1;
    if (n == 2) return 2;

    if (memo[n - 1] == 0)
    {
        memo[n - 1] = f (n - 1, memo) + (n - 1) * f (n - 2, memo);
    }
    printf ("%d\n", memo[n - 1]);
    return memo[n - 1];
}

int calc (int n)
{
    int memo[MAXN] = {};

    return f (n, memo);
}

int main ()
{
    printf ("Value: %d\n", calc (10));

    return 0;
}