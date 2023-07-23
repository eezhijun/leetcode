#include "internal.h"

/* https://leetcode.cn/problems/divide-two-integers/ */

int divide(int dividend, int divisor){
    // -2^32 / -1 = 2^32 -- 2^32-1
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;

    // dividend = abs(dividend);
    // divisor = abs(divisor);
    if (dividend > 0) {
        dividend = -dividend;
    }
    if (divisor > 0) {
        divisor = -divisor;
    }
    // printf("%d %d\n", dividend, divisor);

    int res = 0;
    while (dividend <= divisor) {
        int value = divisor;
        int k = 1;

        while (value >= 0xC0000000 && dividend <= value + value) {
            value += value;
            if (k > INT_MAX / 2) {
                return INT_MIN;
            }
            k += k;
        }
        dividend -= value;
        res += k;
    }
    return sign * res;
}


void divideTest(void)
{
    int dividend = 10;
    int divisor = 3;

    int ans = divide(dividend, divisor);

    printf("output: %d\n", ans);
}
