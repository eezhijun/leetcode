#include "common.h"

/* https://leetcode.cn/problems/remove-duplicates-from-sorted-array/ */


int removeDuplicates(int* nums, int numsSize)
{
    int s = 0, f = 1;
    while (s < f && f < numsSize) {
        if (nums[s] != nums[f]) {
            s++;
        }
        f++;
        if (f - s > 1) {
            nums[s] = nums[f - 1];
        }
    }
    return s + 1;
}

void removeDulicatesTest(void)
{

}
