#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* https://leetcode.cn/problems/zero-matrix-lcci/ */

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int M = matrixSize;
    int N = *matrixColSize;
    int *rowRecord = (int *)malloc(sizeof(int *) * M);
    if (rowRecord == NULL) {
        return;
    }
    int *colRecord = (int *)malloc(sizeof(int *) * N);
    if (colRecord == NULL) {
        return;
    }

    memset(rowRecord, 0, sizeof(int *) * M);
    memset(colRecord, 0, sizeof(int *) * N);

    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (matrix[i][j] == 0) {
                rowRecord[i] = 1;
                colRecord[j] = 1;
            }
        }
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (rowRecord[i] == 1 || colRecord[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }

    free(rowRecord);
    free(colRecord);

}
