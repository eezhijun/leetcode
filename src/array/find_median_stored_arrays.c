#include "common.h"


void bubbleSort (int arr[], int len)
{
    int i, j,temp;
    _Bool exchanged = true;

    for (i=0; exchanged && i<len-1; i++){
        exchanged = false;
        for (j=0; j<len-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                exchanged = true;
            }
        }
    }
}

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

    bubbleSort(arr, size);

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
