#include "common.h"


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for (int i = 0; i < numsSize - 1; ++i) {
        for (int j = 0; j < numsSize - i - 1; ++j) {
            if (nums[i] + nums[j + i + 1] == target) {
                int *ret = (int *)malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j + i + 1;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

void twoSumTest(void)
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize;


    int *ans = twoSum(nums, numsSize, target, &returnSize);

    printf("output: [%d,%d]\n", ans[0], ans[1]);
}
