#include "stdio.h"
#include "utils.h"

/* https://leetcode.cn/problems/median-of-two-sorted-arrays/ */


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    int size = nums1Size + nums2Size;
    int arr[size];

    for (int i = 0; i < size; i++) {
        if (i < nums1Size) {
            arr[i] = nums1[i];
        } else {
            arr[i] = nums2[i - nums1Size];
        }
    }

    bubble_sort(arr, size);

    if (size % 2 != 0) {
        return (double)arr[(size - 1) / 2];
    }
    return (double)(arr[size / 2] + arr[size / 2 - 1]) / 2;

}

void findMedianSortedArraysTest(void)
{
    int nums1[2] = {1, 3};
    int nums2[1] = {2};
    int nums1Size = sizeof(nums1) / sizeof(int);
    int nums2Size = sizeof(nums2) / sizeof(int);

    double ans = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

    printf("output: %fd\n", ans);
}
