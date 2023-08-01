#include "stdio.h"
#include "stdlib.h"
#include "common.h"

/* https://leetcode.cn/problems/array-partition/ */

int arrayPairSum(int *nums, int numsSize)
{
    if (nums == NULL) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < numsSize; i += 2) {
        ans += nums[i];
    }
    return ans;
}
