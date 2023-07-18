#include "common.h"

/* https://leetcode.cn/problems/rotate-image/ */

void rotate_image(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, temp;

    // 上下换
    for (i = 0; i < matrixSize / 2; i++) {
        for (j = 0; j < matrixSize; j++) {
            temp = matrix[matrixSize - i - 1][j];
            matrix[matrixSize - i - 1][j] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }

    // 对角线换
    for (i = 0; i < matrixSize; i++) {
        for (j = i + 1; j < matrixSize; j++) {
            temp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }

}

/* https://leetcode.cn/problems/rotate-matrix-lcci/submissions/ */


void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    // 水平翻转
    for (int i = 0; i < matrixSize / 2; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            swap(&matrix[i][j], &matrix[matrixSize - i - 1][j]);
        }
    }
    // 主对角线翻转
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}
