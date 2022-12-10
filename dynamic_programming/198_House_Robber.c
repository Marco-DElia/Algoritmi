#define MAX(X,Y) X > Y ? X : Y

int solve (int *nums, int numsSize, int *memo, int index)
{
    if (index == numsSize - 1) return nums[index];
    if (index > numsSize - 1) return 0;

    if (memo[index] == -1)

        memo[index] = MAX (nums[index] + solve (nums, numsSize, memo, index + 2), solve (nums, numsSize, memo, index + 1));

    return memo[index];
}

int rob(int* nums, int numsSize){

    int memo[400];
    for (int i = 0; i < 400; i++) memo[i] = -1;

    return solve (nums, numsSize, memo, 0);
}