#include <stdio.h>
#include <stdlib.h>

#define max(x, y) x > y ? x : y

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int solve (int *nums, int numsSize, int *memo, int index)
{
    if (index >= numsSize) return 0;

    if (memo[index] == -1)
    {
        int i = 0, sum = 0;
        for (i = index; i < numsSize && nums[i] == nums[index]; i++) sum += nums[i];
        for (; i < numsSize && nums[i] == nums[index] + 1; i++);

        memo[index] = max (sum + solve (nums, numsSize, memo, i), solve (nums, numsSize, memo, index + 1));
    }
    return memo[index];
}

int deleteAndEarn(int* nums, int numsSize){

    int *memo = malloc (sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) memo[i] = -1;

    qsort (nums, numsSize, sizeof(int), cmpfunc);

    return solve (nums, numsSize, memo, 0);
}