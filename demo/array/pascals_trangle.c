#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* https://leetcode.cn/problems/pascals-triangle/ */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    if (returnSize == NULL || returnColumnSizes == NULL) {
        return NULL;
    }
    // printf("%s\n", __func__);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    int **ret = (int **)malloc(sizeof(int *) * numRows);
    ret[*returnSize] = (int *)malloc(sizeof(int) * 1);
    ret[*returnSize][0] = 1;
    (*returnColumnSizes)[*returnSize] = 1;
    (*returnSize)++;
    int i, j;
    for (i = 1; i < numRows; i++) {
        ret[*returnSize] = (int *)malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[*returnSize] = i + 1;
        for (j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                ret[*returnSize][j] = 1;
            } else {
                ret[*returnSize][j] = ret[*returnSize - 1][j - 1] + ret[*returnSize - 1][j];
                //printf("*returnSize=%d, j=%d, retret[*returnSize][j]=%d\n", *returnSize, j, ret[*returnSize][j]);
            }
        }
        // if (i == 2) {
        //     printf("i=%d\n", i);
        //     return NULL;
        // }
        (*returnSize)++;
    }
    return ret;
}

/* https://leetcode.cn/problems/pascals-triangle-ii/ */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)
{
    if (returnSize == NULL) {
        return NULL;
    }
    *returnSize = rowIndex + 1;
    int *ret = (int *)malloc(sizeof(int) * (rowIndex + 1));
    int *pre_ret = (int *)malloc(sizeof(int) * (rowIndex + 1));
    if (ret == NULL || pre_ret == NULL) {
        return NULL;
    }
    memset(ret, 0, sizeof(int) * (rowIndex + 1));
    memset(pre_ret, 0, sizeof(int) * (rowIndex + 1));
    int i, j;
    for (i = 0; i < rowIndex + 1; i++) {
        ret[0] = ret[i] = 1;
        for (j = 1; j < i + 1; j++) {
            ret[j] = pre_ret[j - 1] + pre_ret[j];
        }
        int *tmp = pre_ret;
        pre_ret = ret;
        ret = tmp;
    }
    return pre_ret;
}
