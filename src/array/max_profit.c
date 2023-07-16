#include "common.h"

/* https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/ */

int maxProfit(int* prices, int pricesSize){
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
