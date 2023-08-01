#include "stdio.h"
#include "stdbool.h"

/* https://leetcode.cn/problems/minimum-size-subarray-sum/ */

int minSubArrayLen(int target, int *nums, int numsSize)
{
    if (nums == NULL) {
        return 0;
    }
    // 尺缩法
    int slow = 0, fast = 1, gap = 0, is_first_time = true;
    int sum = nums[slow];

    if (sum >= target) {
        return 1;
    }

    for (fast = 1; fast < numsSize; fast++) {
        sum += nums[fast];
        if (sum >= target) { // 2+3+1+2+4+3
            //printf("1_sum=%d\n", sum);
            for (; slow < fast + 1; slow++) {
                sum -= nums[slow];
                if (sum < target) {
                    sum += nums[slow];
                    if (is_first_time) {
                        gap = fast - slow + 1;
                        is_first_time = false;
                    }
                    if (fast - slow + 1 < gap) {
                        gap = fast - slow + 1;
                    }
                    //printf("2_sum=%d, gap=%d\n", sum, gap);
                    if (gap == 1) {
                        return 1;
                    }
                    break;
                }
            }
        }
    }

    return gap;
}
