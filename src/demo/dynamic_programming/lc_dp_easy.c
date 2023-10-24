/**
 * @file lc_dp_easy.c
 * @author hongzhijun (eehongzhijun@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "stdio.h"

/* 数学归纳法 */

/* https://leetcode.cn/problems/climbing-stairs/ */
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

示例 1：

输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶
示例 2：

输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶

提示：

1 <= n <= 45 */
int climbStairs(int n)
{
    if (n <= 2) {
        return n;
    }

    int dp[n + 1];
    int i;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int climbStairsTest(void)
{
    int n = 4;
    printf("input:%d\n", n);
    int ret = climbStairs(n);
    printf("output:%d\n", ret);
    return 0;
}

int lc_dp_easy_test(void)
{
    int ret = -1;
    // ret = climbStairsTest();
    return ret;
}
