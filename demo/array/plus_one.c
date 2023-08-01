#include "stdio.h"
#include "stdlib.h"

/* https://leetcode.cn/problems/plus-one/ */

int* plusOne(int* digits, int digitsSize, int* returnSize){
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] != 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        } else {
            digits[i] = 0;
        }
    }
    *returnSize = digitsSize + 1;
    int *tmp = (int *)malloc(sizeof(int) * (digitsSize + 1));
    if (tmp == NULL) {
        *returnSize = 0;
        return tmp;
    }
    for (int i = 1; i < digitsSize + 1; i++) {
        tmp[i] = digits[i - 1];
    }
    tmp[0] = 1;
    return tmp;
}
