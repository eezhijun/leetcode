#include "internal.h"

/* https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/ */

int maxProfit2(int* prices, int pricesSize){
    if (prices == NULL || pricesSize < 2) {
        return 0;
    }

    int index = 0, tatol = 0;
    while (index < pricesSize) {
        while (index < pricesSize - 1 && prices[index] >= prices[index + 1]) {
            index++;
        }

        int min = prices[index];
        while (index < pricesSize - 1 && prices[index] <= prices[index + 1]) {
            index++;
        }

        tatol += prices[index++] - min;
    }
    return tatol;
}

/* https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/ */

int maxProfit(int* prices, int pricesSize){
    int tmp = prices[0];
    int diff = 0;
    int i;

    for (i = 1; i < pricesSize; i++)
    {
        if (tmp >= prices[i])
        {
            tmp = prices[i];
        }
        else if (diff < (prices[i] - tmp))
        {
            diff = prices[i] - tmp;
        }
    }

    return diff;
}

void maxProfitTest(void)
{
    // int nums[] = {7,1,5,3,6,4};
    int nums[] = {7,6,4,3,1};
    int numsSize = sizeof(nums) / sizeof(int);

    int ans = maxProfit(nums, numsSize);

    printf("output: ans=%d\n", ans);
}
