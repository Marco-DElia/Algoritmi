#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solve(int n, int *memo){

    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    if (memo[n - 1] == 0)

        memo[n - 1] = solve (n - 1, memo) + solve (n - 2, memo);

    return memo[n - 1];
}

int climbStairs(int n){

    int *memo = malloc (sizeof (int) * n);
    memset (memo, 0, sizeof (int) * n);

    return solve (n, memo);
}

int main ()
{
    printf ("%d", climbStairs (10));

    return 0;
}