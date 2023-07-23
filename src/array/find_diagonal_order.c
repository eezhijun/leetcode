#include "internal.h"

/* https://leetcode.cn/problems/diagonal-traverse/ */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    if (mat == NULL) {
        return NULL;
    }
    int M = matSize; // 行数
    int N = *matColSize; // 列数
    int tot = M + N - 1; // 对角线个数
    int *res = (int *)malloc(sizeof(int) * M * N); // 申请一块存放结果的内存

    int i, index = 0;
    int r = 0, c = 0; // r:横坐标 c:纵坐标
    for (i = 0; i < tot; i++) {
        if (i % 2 == 0) { // 对角线正向
            while (r >= 0 && c < N) {
                res[index++] = mat[r][c];
                r -= 1;
                c += 1;
            }
            if (c < N) {
                r += 1;
            } else {
                r += 2;
                c -= 1;
            }
        } else { // 对角线反向
            while (c >= 0 && r < M) {
                res[index++] = mat[r][c];
                r += 1;
                c -= 1;
            }
            if (r < M) {
                c += 1;
            } else {
                c += 2;
                r -= 1;
            }
        }
    }
    *returnSize = index;
    return res;
}
