#include "internal.h"

/* https://leetcode.cn/problems/container-with-most-water/ */

int Min(int a, int b)
{
    return (a > b) ? b : a;
}

int Max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxArea(int* height, int heightSize){
    int l = 0, r = heightSize - 1;
    int maxA = 0;

    while (l < r) {
        int temp = Min(height[l], height[r]) * (r - l);
        maxA = Max(temp, maxA);
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
