/**
 * @file lc_bin_search_easy.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

#include "utils.h"

/* https://leetcode.cn/leetbook/read/binary-search/xexoac/ */
/* 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target，
写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 

提示：

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。*/
int search(int *nums, int numsSize, int target)
{
    int l = 0, r = numsSize - 1;
    int ret = -1;
    /*
    (r+l)/2 平均可能会溢出，原因是(r+l)/2有可能超出int类型范围
    可以采取l+(r-l)/2，也可以用l+(r-l)>>1
*/

    int mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] > target) {
            r = mid - 1;
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            ret = mid;
            break;
        }
    }

    return ret;
}

void searchTest(void)
{
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int numsSize = ARRAY_SIZE(nums);
    int target = 9;

    printf("input:\n");
    PRINT_ARRAY(nums, numsSize, "%d ");
    int ret = search(nums, numsSize, target);
    printf("output:%d\n", ret);
}

int lc_bin_search_easy_test(void)
{
    searchTest();
    return 0;
}
