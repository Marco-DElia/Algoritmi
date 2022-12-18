#include <stdarg.h>

int min(int cnt,...)
{
    va_list ap;
    int i, current, minimum = INT_MAX;

    va_start(ap, cnt);

    for (i=0; i<cnt; i++)
    {
        current = va_arg(ap, int);
        if (current < minimum)
            minimum = current;
    }
    va_end(ap);

    return minimum;
}

int solve (char *word1, char *word2, int *memo, int m, int n, int i, int j) // n = taglia word2
{
    if (j >= n && i >= m) return 0;
    if (j >= n) return m - i;
    if (i >= m) return n - j;

    if (memo[i*n + j] != -1) return memo[i*n + j];// già c'è il risultato memoizzato

    // elementi uguali, avanzo senza costi
    int m1 = INT_MAX, m2 = INT_MAX;
 
    if (word1[i] == word2[j]) m1 = solve (word1, word2, memo, m, n, i + 1, j + 1);
    else m2 = 1 + min (3, solve (word1, word2, memo, m, n, i + 1, j + 1), //copia
                        solve (word1, word2, memo, m, n, i, j + 1),     // aggiungi
                        solve (word1, word2, memo, m, n, i + 1, j));    // elimina

    memo[i*n + j] =  min (2, m1, m2);
 
    return memo[i*n + j];
}


int minDistance(char * word1, char * word2)
{
    int m = strlen (word1);
    int n = strlen (word2);

    int *memo = malloc (sizeof(int)*m*n);
    memset (memo, -1, m*n*sizeof(int));

    int r = solve (word1, word2, memo, m, n, 0, 0);
    free (memo);


    return r;
}