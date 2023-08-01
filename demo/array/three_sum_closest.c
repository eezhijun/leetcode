#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "common.h"

/* https://leetcode.cn/problems/3sum-closest/ */


int threeSumClosest(int* nums, int numsSize, int target){
    int sum = 0;
    int i;
    int left;
    int right;
    int closest = 0;
    int tmp;
    int flag = false;

    qsort(nums, numsSize, sizeof(int), cmp);
    print_array(nums, numsSize);

    for (i = 0; i < numsSize - 2; i++)
    {
        for (left = i + 1, right = numsSize - 1; left != right;)
        {
            sum = nums[i] + nums[left] + nums[right];
            if (sum == target)
            {
                return sum;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }

            if (!flag)
            {
                flag = true;
                tmp = abs(target - sum);
                closest = sum;
            }
            else if (tmp > abs(target - sum))
            {
                tmp = abs(target - sum);
                closest = sum;
            }
        }
    }

    return closest;
}

/*
    升序
    -4 -1 1 2
    -5 -5 -4 0 0 3 3 4 5
    2 3 8 9 10
*/
void threeSumClosestTest(void)
{
    // int nums[] = {-1,2,1,-4};
    // int nums[] = {4,0,5,-5,3,3,0,-4,-5};
    // int nums[] = {1,1,1,0};
    int nums[] = {2,3,8,9,10};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 16;

    int ans = threeSumClosest(nums, numsSize, target);

    printf("output: ans=%d\n", ans);
}
