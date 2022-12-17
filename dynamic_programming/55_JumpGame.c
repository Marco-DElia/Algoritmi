bool solve (int *nums, int numsSize, int *memo, int index)
{
    if (index == numsSize - 1) return true;

    if (memo[index] == -1)
    {
        bool find = false;
        int i = nums[index];
        while (!find && i > 0)
        {
            if (i + index < numsSize && solve (nums, numsSize, memo, index + i))
            {
                find = true;
                memo[index + i] = true;
            }
            i--;
        }
        if (!find)  memo[index] = false;
        else
        {
            printf ("riuso\n");
            memo[index] = true;
        }
    }
    return memo[index];
}

bool canJump(int* nums, int numsSize){

    int *memo = malloc (sizeof (int) * numsSize);

    for (int i = 0; i < numsSize; i++) memo[i] = -1;

    int m = solve (nums, numsSize, memo, 0);
    free (memo);

    return m;
}