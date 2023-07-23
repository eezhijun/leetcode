#include "internal.h"

/* https://leetcode.cn/problems/max-consecutive-ones/ */

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    if (nums == NULL) {
        return 0;
    }
    int max = 0, cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            cnt++;
        } else {
            cnt = 0;
        }
        max = MAX(max, cnt);
    }
    return max;
}
