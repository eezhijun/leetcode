#include "common.h"

/* https://leetcode.cn/problems/valid-sudoku/ */

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int cnt[9];
    int i, j;

    memset(cnt, 0, sizeof(int) * 9);

    // 行检查
    for (i = 0; i < 9; i++) {
        memset(cnt, 0, sizeof(int) * 9);
        for (j = 0; j < 9; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                int value = board[i][j] - '0' - 1;
                if (cnt[value]) {
                    return false;
                }
                cnt[value]++;
            }
        }
    }

    // 列检查
    for (i = 0; i < 9; i++) {
        memset(cnt, 0, sizeof(int) * 9);
        for (j = 0; j < 9; j++) {
            if (board[j][i] >= '1' && board[j][i] <= '9') {
                int value = board[j][i] - '0' - 1;
                if (cnt[value]) {
                    return false;
                }
                cnt[value]++;
            }
        }
    }

    // 宫检查
    int k;
    for (k = 0; k < 9; k++) {
        memset(cnt, 0, sizeof(int) * 9);
        i = (k % 3) * 3;
        j = (k / 3) * 3;
        int tempi, tempj;
        for (tempi = 0; tempi < 3; tempi++) {
            for (tempj = 0; tempj < 3; tempj++) {
                if (board[i + tempi][j + tempj] >= '1' && board[i + tempi][j + tempj] <= '9') {
                    int value = board[i + tempi][j + tempj] - '0' - 1;
                    if (cnt[value]) {
                        return false;
                    }
                    cnt[value]++;
                }
            }
        }
    }
    return true;
}
