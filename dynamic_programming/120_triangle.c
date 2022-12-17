int min (int a, int b)
{
    if (a <= b) return a;
    else return b;
}

int solve (int **triangle, int triangleSize, int *memo, int i, int j)
{
    // triangleSize è anche il numero di colonne della memoization
    // i è il numero di riga, j il numero di colonna
    if (i >= triangleSize) return 0;
    if (memo[i*triangleSize + j] != -1) return memo[i*triangleSize + j];

    // calcolo il minimo tra l'andare in basso e l'andare in basso a destra
    memo[i*triangleSize + j] = triangle[i][j] + min (solve (triangle, triangleSize, memo, i + 1, j), solve (triangle, triangleSize, memo, i + 1, j + 1));

    return memo[i*triangleSize + j];
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){

    int *memo = malloc (sizeof(int) *triangleSize*triangleSize);
    //printf ("%d\n", triangleSize);
    memset (memo, -1, sizeof(int)*triangleSize*triangleSize);

    int n = solve (triangle, triangleSize, memo, 0, 0);
    free(memo);

    return n;
}