int solve (int **matrix, int m, int n, int *memo, int i, int j)
{
    if (i >= m-1 && j >= n-1) return 1 - matrix[i][j];
    //if (i == m-1 && j == n-2) return 1;
    //if (i == m-2 && j == n-1) return 1;
    if (memo[i*n + j] != 0) return memo[i*n + j];

    if (j == n-1)
    {
        if (matrix[i+1][j] == 0)
            memo[i*n + j] = solve (matrix, m, n, memo, i+1, j);
    }
    else if(i == m-1)
    {
        if (matrix[i][j+1] == 0)
            memo[i*n + j] = solve (matrix, m, n, memo, i, j+1);
    }
    else
    {
        if (matrix[i+1][j] == 0)
            memo[i*n + j] = solve (matrix, m, n, memo, i+1, j);

        if (matrix[i][j+1] == 0)
            memo[i*n + j] += solve (matrix, m, n, memo, i, j+1);
    }

    return memo[i*n+j];
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){

    int memo[100*100];

    memset (memo, 0, sizeof(int)*100*100);

    if (obstacleGrid[0][0]) return 0;
    return solve (obstacleGrid, obstacleGridSize, *obstacleGridColSize, memo, 0, 0);
}