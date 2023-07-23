#include "internal.h"

/* https://leetcode.cn/problems/two-sum/ */

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

/* https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/ */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum2(int *numbers, int numbersSize, int target, int *returnSize)
{
    if (numbers == NULL || returnSize == NULL) {
        return NULL;
    }
    int *ans = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;

    int left = 0, right = numbersSize - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            ans[0] = left + 1;
            ans[1] = right + 1;
            return ans;
        } else if (sum > target) {
            right--;
        } else {
            left++;
        }
    }
    return NULL;
}
