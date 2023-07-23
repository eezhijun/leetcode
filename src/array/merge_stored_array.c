#include "internal.h"

/* https://leetcode.cn/problems/merge-sorted-array/ */

void arr_right_shift(int *nums, int len, int s, int e)
{
    for (int i = s; i > e; i--) {
        nums[i] = nums[i - 1];
    }
}

void merge_stored_array(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    if (nums2 == NULL || n == 0) {
        return;
    }
    int i, j;
    int offset = m;
    for (i = 0, j = 0; i < nums1Size && j < nums2Size; i++) {
        if (i < offset && m != 0) {
            if (nums1[i] >= nums2[j]) {
                arr_right_shift(nums1, nums1Size, offset, i);
                offset++;
                nums1[i] = nums2[j];
                j++;
            }
        } else {
            nums1[i] = nums2[j];
            j++;
        }
    }
}
