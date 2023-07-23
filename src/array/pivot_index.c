#include "internal.h"

/* https://leetcode.cn/problems/find-pivot-index/ */

int pivotIndex(int* nums, int numsSize){
    int i;
    int sum = 0;
    int left = 0;

    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    for (i = 0; i < numsSize; i++) {
        if (left * 2 + nums[i] == sum) {
            return i;
        }
        left += nums[i];
    }
    return -1;
}
