#include "common.h"

/* https://leetcode.cn/problems/move-zeroes/ */

void moveZeroes(int* nums, int numsSize){
    if (nums == NULL) {
        return;
    }
    int i, j = 0;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            j++;
        } else if (j != 0) {
            nums[i - j] = nums[i];
            nums[i] = 0;
        }
    }
}
