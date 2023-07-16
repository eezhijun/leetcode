#include "common.h"

/* https://leetcode.cn/problems/3sum/ */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    bubbleSort(nums, numsSize);

    *returnSize = 0;
    short left = 0;
    short right = numsSize - 1;

    int **ret = (int **)malloc(sizeof(int *) * (numsSize + 1) * 6);
    *returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 6);
    ret[*returnSize] = malloc(sizeof(int) * 3);

    while (left + 1 < right) {
        int i = left + 1;
        int j = right;
        while (i < j) {
            if (nums[i] + nums[j] + nums[left] < 0) {
                i++;
            } else if (nums[i] + nums[j] + nums[left] > 0) {
                j--;
            } else {
                ret[*returnSize][0] = nums[left];
                ret[*returnSize][1] = nums[i];
                ret[*returnSize][2] = nums[j];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                ret[*returnSize] = malloc(sizeof(int) * 3);

                while(nums[i] == nums[++i] && i < j) {}
                while(nums[j] == nums[--j] && i < j) {}
            }
        }
        while(nums[left] == nums[++left] && left + 1 < right) {}
    }

    return ret;
}

void threeSumTest(void)
{
    int nums[] = {-1,0,1,2,-1,-4};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize;
    int *returnColumnSizes;

    int **ans = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

}
