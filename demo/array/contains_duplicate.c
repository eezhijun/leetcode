#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "utils.h"

/* https://leetcode.cn/problems/contains-duplicate/ */


bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}
