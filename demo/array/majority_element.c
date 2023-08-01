#include "stdio.h"
#include "common.h"

/* https://leetcode.cn/problems/majority-element/ */

int majorityElement(int* nums, int numsSize){
    if (numsSize <= 2)
    {
        return nums[0];
    }
    bubble_sort(nums, numsSize);

    int count = 1;
    int i;
    int cond = numsSize / 2;

    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            count++;
            if (count > cond)
            {
                return nums[i];
            }
        }
    }
    return 0;
}

void majorityElementTest(void)
{
    int nums[] = {3,2,3};
    // int nums[] = {2,2,1,1,1,2,2};
    int numsSize = sizeof(nums) / sizeof(int);

    int ans = majorityElement(nums, numsSize);

    printf("output: ans=%d\n", ans);
}
