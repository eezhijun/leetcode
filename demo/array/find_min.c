#include "stdio.h"

/* https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/ */

int findMin(int* nums, int numsSize)
{
    int min = nums[0];
    int i;
    for (i = 1; i < numsSize; i++){
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}
