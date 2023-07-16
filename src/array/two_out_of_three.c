#include "common.h"

/* https://leetcode.cn/problems/two-out-of-three/ */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAX_LEN 100

int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize){

    int mp[MAX_LEN + 1];
    memset(mp, 0, sizeof(int) * (MAX_LEN + 1));
    int i;
    for (i = 0; i < nums1Size; i++) {
        mp[nums1[i]] = 1;
    }
    for (i = 0; i < nums2Size; i++) {
        mp[nums2[i]] |= 2;
    }
    for (i = 0; i < nums3Size; i++) {
        mp[nums3[i]] |= 4;
    }
    int pos = 0;
    int *res = (int *)malloc(sizeof(int) * MAX_LEN);
    if (res == NULL) {
        return NULL;
    }
    memset(res, 0, sizeof(int) * MAX_LEN);
    for (i = 0; i <= MAX_LEN; i++) {
        if (mp[i] & (mp[i] - 1)) {
            res[pos] = i;
            pos++;
        }
    }
    *returnSize = pos;
    return res;


}
