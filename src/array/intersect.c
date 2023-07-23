#include "common.h"

/* https://leetcode.cn/problems/intersection-of-two-arrays-ii/ */


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    bubble_sort(nums1, nums1Size);
    bubble_sort(nums2, nums2Size);

    int minLen = nums1Size > nums2Size ? nums2Size : nums1Size;
    int *ans = (int *)malloc(sizeof(int) * minLen);
    if (ans == NULL) {
        *returnSize = 0;
        return ans;
    }
    int i = 0, j = 0, cnt = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            ans[cnt] = nums1[i];
            i++;
            j++;
            cnt++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            i++;
        }
    }
    *returnSize = cnt;
    return ans;
}
