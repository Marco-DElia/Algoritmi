int max_pal (char *string, int i, int j, int *memo, int size)
{
    if (memo[i*size + j] != -1) return memo[i*size + j];

    if (i > j) return 0;
    if (i == j) return 1;

    int m = 0;
    int count = 0;
    if (string[i] == string[j])
    {
        count += 2;
        count += max_pal (string, i + 1, j - 1, memo, size);
    }
    else
    {
        int ml = max_pal (string, i + 1, j, memo, size);
        int mr = max_pal (string, i, j - 1, memo, size);

        m = ml > mr ? ml : mr;
    }
    
    memo[i*size + j] = count > m ? count : m;

    return memo[i*size + j];
}

int longestPalindromeSubseq(char * string){
    int size = strlen (string);

    int *memo = malloc (sizeof (int) * size * size);
    if (memo == NULL) return -1;

    for (int i = 0; i < size * size; i++) memo[i] = -1;

    return max_pal (string, 0, size - 1, memo, size);
}