#include "internal.h"

/* https://leetcode.cn/problems/remove-element/ */

int removeElement(int *nums, int numsSize, int val)
{
    if (nums == NULL) {
        return 0;
    }
    int fast, slow;
    for (slow = 0, fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}
