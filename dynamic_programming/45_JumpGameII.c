int solve (int *nums, int numsSize, int *memo, int index)
{
    if (index >= numsSize - 1) return 0;

    if (memo[index] == -1)
    {
        int min = numsSize;
        int m;
        // La memo contiene il numero di jups per arrivare ad numsSize - 1
        for (int i = 1; i <= nums[index]; i++)
        {
            m =  1 + solve (nums, numsSize, memo, index + i);
            if (m < min) min = m;
        }
        memo[index] = min;
    }
    return memo[index];
}

int jump(int* nums, int numsSize){

    int *memo = malloc (sizeof (int) * numsSize);
    for (int i = 0; i < numsSize; i++) memo[i] = -1;

    int m = solve (nums, numsSize, memo, 0);
    free (memo);

    return m;
}