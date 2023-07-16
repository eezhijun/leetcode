#include "common.h"

/* https://leetcode.cn/problems/merge-intervals/ */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** merge_intervals(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    if (intervalsSize == 1) {
        *returnSize = 1;
        return intervals;
    }
    qsort(intervals, intervalsSize,sizeof(int*), cmp);
    int** result = (int**)malloc(sizeof(int*) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        result[i] = (int*)malloc(sizeof(int) * 2);
    }
    *returnSize = 0;
    int temp[2] = {intervals[0][0],intervals[0][1]};
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= temp[1]) { //如果遍历到的为重叠的区间，进行合并
            temp[1] = fmax(temp[1],intervals[i][1]);
        }
        else { //不重叠
            result[*returnSize][0] = temp[0];
            result[*returnSize][1] = temp[1];
            temp[0] = intervals[i][0];
            temp[1] = intervals[i][1];
            (*returnSize) += 1;
        }
    }
    result[*returnSize][0] = temp[0];
    result[*returnSize][1] = temp[1];
    *returnSize += 1;
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < *returnSize; i++){
        (*returnColumnSizes)[i] = 2;
    }
    return result;
}
