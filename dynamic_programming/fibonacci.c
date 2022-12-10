#include <stdio.h>

int fib (int n, int memo[])
{
    //printf ("call\n");

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

int fib_bottom_up (int n)
{
    if (n == 1 || n == 2) return 1;

    int result = 0;
    int a = 1;
    int b = 1;

    for (int i = 3; i <= n; i++)
    {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main ()
{
    int memo[100000] = {};

    printf ("fib: %d\n", fib (24, memo));
    printf ("fib: %d\n", fib_bottom_up (24));


    return 0;
}