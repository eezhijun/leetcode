#include "stdio.h"
#include "common.h"

/* https://leetcode.cn/problems/container-with-most-water/ */

int maxArea(int* height, int heightSize){
    int l = 0, r = heightSize - 1;
    int maxA = 0;

    while (l < r) {
        int temp = min(height[l], height[r]) * (r - l);
        maxA = max(temp, maxA);
        if (height[l] <= height[r]) {
            ++l;
        } else {
            --r;
        }
    }
    return maxA;
}

void maxAreaTest(void)
{
    int height[] = {1,8,6,2,5,4,8,3,7};
    int heightSize = sizeof(height) / sizeof(int);

    int ans = maxArea(height, heightSize);

    printf("output: %d\n", ans);
}
