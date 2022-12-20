int solve (int m, int n, int *memo, int i, int j)
{
    if (i >= m-1 || j >= n-1) return 1;
    if (memo[i*n + j] != 0) return memo[i*n + j];

    memo[i*n + j] = solve (m, n, memo, i+1, j) + solve (m, n, memo, i, j+1);

    return memo[i*n+j];
}

int uniquePaths(int m, int n){

    int memo[100*100];
    //for (int i = 0; i < 100*100; i++) memo[i] = -1;
    memset (memo, 0, sizeof(int)*100*100);

    return solve (m, n, memo, 0, 0);
}