#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max (int a, int b)
{
    if (a >= b) return a;
    return b;
}

int solve (char string[], int *memo, int n, int i, int j)
{
    if (i == j) return 1;
    if (i > j) return 0;

    if (memo[i*n + j] != -1) return memo[i*n + j];

    if (string[i] == string[j]) memo[i*n + j] = 2 + solve (string, memo, n, i + 1, j - 1);
    else memo[i*n + j] = max (solve (string, memo, n, i + 1, j), solve (string, memo, n, i, j - 1));
    
    return memo[i*n + j];
}

int tocall (char string[])
{
    int memo[1000];
    for (int i = 0; i < 1000; i++) memo[i] = -1;
    return solve (string, memo, strlen(string), 0, strlen(string));
}


int main ()
{
    char string[100];
    int T;

    scanf ("%d", &T);
    while (T--)
    {
        scanf ("%s", string);
        printf ("ciao: %d\n", tocall (string));
    }



    return 0;
}