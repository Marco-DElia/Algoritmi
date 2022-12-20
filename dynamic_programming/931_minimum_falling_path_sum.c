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


int solve (int **matrix, int n, int *memo, int i, int j)
{
    if (j < 0 || j >= n) return 100*100*100;
    if (i >= n) return 0;
    if (memo[i*n + j] != -1) return memo[i*n + j];

    memo[i*n + j] = matrix[i][j] + min (3, solve (matrix, n, memo, i+1, j-1),
                                           solve (matrix, n, memo, i+1, j),
                                           solve (matrix, n, memo, i+1, j+1));
    return memo[i*n + j];
}

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize){

    int memo[100*100];

    int min = INT_MAX, r;
    memset (memo, -1, sizeof(int) * 100*100);

    for (int i = 0; i < matrixSize; i++)
    {
        r = solve (matrix, matrixSize, memo, 0, i);
        if (min > r) min = r;
    }
    return min;
}