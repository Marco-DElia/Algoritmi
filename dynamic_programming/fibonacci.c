#include <stdio.h>

int fib (int n, int memo[])
{
    printf ("call\n");

    if (n == 1) return 1;
    if (n == 2) return 1;

    if (memo[n] == 0)
    {
        memo[n] = fib (n - 1, memo) + fib (n - 2, memo);
    }

    return memo[n];
}

int fib_no_memo (int n)
{
    printf ("call\n");

    if (n == 1) return 1;
    if (n == 2) return 1;

    return fib_no_memo (n - 1) + fib_no_memo (n - 2);
}

int main ()
{
    int memo[100] = {};

    printf ("fib: %d\n", fib (11, memo));


    return 0;
}