/**
 * @file lc_array.c
 * @author eehongzhijun (eehongzhijun@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "limits.h"
#include "string.h"
#include "math.h"

#include "utils.h"

/* https://leetcode.cn/problems/array-partition/ */

int arrayPairSum(int *nums, int numsSize)
{
    if (nums == NULL) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < numsSize; i += 2) {
        ans += nums[i];
    }
    return ans;
}

/* https://leetcode.cn/problems/contains-duplicate/ */

bool containsDuplicate(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}

/* https://leetcode.cn/problems/divide-two-integers/ */

int divide(int dividend, int divisor)
{
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

/* https://leetcode.cn/problems/diagonal-traverse/ */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDiagonalOrder(int **mat, int matSize, int *matColSize, int *returnSize)
{
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

/* https://leetcode.cn/problems/max-consecutive-ones/ */

int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    if (nums == NULL) {
        return 0;
    }
    int max = 0, cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            cnt++;
        } else {
            cnt = 0;
        }
        max = MAX(max, cnt);
    }
    return max;
}

/* https://leetcode.cn/problems/median-of-two-sorted-arrays/ */

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size)
{
    int size = nums1Size + nums2Size;
    int arr[size];

    for (int i = 0; i < size; i++) {
        if (i < nums1Size) {
            arr[i] = nums1[i];
        } else {
            arr[i] = nums2[i - nums1Size];
        }
    }

    bubble_sort(arr, size);

    if (size % 2 != 0) {
        return (double)arr[(size - 1) / 2];
    }
    return (double)(arr[size / 2] + arr[size / 2 - 1]) / 2;
}

void findMedianSortedArraysTest(void)
{
    int nums1[2] = { 1, 3 };
    int nums2[1] = { 2 };
    int nums1Size = sizeof(nums1) / sizeof(int);
    int nums2Size = sizeof(nums2) / sizeof(int);

    double ans = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

    printf("output: %fd\n", ans);
}

/* https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/ */

int findMin(int *nums, int numsSize)
{
    int min = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}

/* https://leetcode.cn/problems/intersection-of-two-arrays-ii/ */

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size,
               int *returnSize)
{
    bubble_sort(nums1, nums1Size);
    bubble_sort(nums2, nums2Size);

    int minLen = nums1Size > nums2Size ? nums2Size : nums1Size;
    int *ans = (int *)malloc(sizeof(int) * minLen);
    if (ans == NULL) {
        *returnSize = 0;
        return ans;
    }
    int i = 0, j = 0, cnt = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            ans[cnt] = nums1[i];
            i++;
            j++;
            cnt++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            i++;
        }
    }
    *returnSize = cnt;
    return ans;
}

/* https://leetcode.cn/problems/valid-sudoku/ */

bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
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
                if (board[i + tempi][j + tempj] >= '1' &&
                    board[i + tempi][j + tempj] <= '9') {
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

/* https://leetcode.cn/problems/majority-element/ */

int majorityElement(int *nums, int numsSize)
{
    if (numsSize <= 2) {
        return nums[0];
    }
    bubble_sort(nums, numsSize);

    int count = 1;
    int i;
    int cond = numsSize / 2;

    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            count++;
            if (count > cond) {
                return nums[i];
            }
        }
    }
    return 0;
}

void majorityElementTest(void)
{
    int nums[] = { 3, 2, 3 };
    // int nums[] = {2,2,1,1,1,2,2};
    int numsSize = sizeof(nums) / sizeof(int);

    int ans = majorityElement(nums, numsSize);

    printf("output: ans=%d\n", ans);
}

/* https://leetcode.cn/problems/container-with-most-water/ */

int maxArea(int *height, int heightSize)
{
    int l = 0, r = heightSize - 1;
    int maxA = 0;

    while (l < r) {
        int temp = min(height[l], height[r]) * (r - l);
        maxA = max(temp, maxA);
        if (height[l] <= height[r]) {
            ++l;
        } else {
            --r;
        }
    }
    return maxA;
}

void maxAreaTest(void)
{
    int height[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    int heightSize = sizeof(height) / sizeof(int);

    int ans = maxArea(height, heightSize);

    printf("output: %d\n", ans);
}

/* https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/ */

int maxProfit2(int *prices, int pricesSize)
{
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

int maxProfit(int *prices, int pricesSize)
{
    int tmp = prices[0];
    int diff = 0;
    int i;

    for (i = 1; i < pricesSize; i++) {
        if (tmp >= prices[i]) {
            tmp = prices[i];
        } else if (diff < (prices[i] - tmp)) {
            diff = prices[i] - tmp;
        }
    }

    return diff;
}

void maxProfitTest(void)
{
    // int nums[] = {7,1,5,3,6,4};
    int nums[] = { 7, 6, 4, 3, 1 };
    int numsSize = sizeof(nums) / sizeof(int);

    int ans = maxProfit(nums, numsSize);

    printf("output: ans=%d\n", ans);
}

/* https://leetcode.cn/problems/merge-intervals/ */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **merge_intervals(int **intervals, int intervalsSize, int *intervalsColSize,
                      int *returnSize, int **returnColumnSizes)
{
    if (intervalsSize == 1) {
        *returnSize = 1;
        return intervals;
    }
    qsort(intervals, intervalsSize, sizeof(int *), cmp);
    int **result = (int **)malloc(sizeof(int *) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        result[i] = (int *)malloc(sizeof(int) * 2);
    }
    *returnSize = 0;
    int temp[2] = { intervals[0][0], intervals[0][1] };
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= temp[1]) { //如果遍历到的为重叠的区间，进行合并
            temp[1] = fmax(temp[1], intervals[i][1]);
        } else { //不重叠
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
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return result;
}

/* https://leetcode.cn/problems/merge-sorted-array/ */

void arr_right_shift(int *nums, int len, int s, int e)
{
    for (int i = s; i > e; i--) {
        nums[i] = nums[i - 1];
    }
}

void merge_stored_array(int *nums1, int nums1Size, int m, int *nums2,
                        int nums2Size, int n)
{
    if (nums2 == NULL || n == 0) {
        return;
    }
    int i, j;
    int offset = m;
    for (i = 0, j = 0; i < nums1Size && j < nums2Size; i++) {
        if (i < offset && m != 0) {
            if (nums1[i] >= nums2[j]) {
                arr_right_shift(nums1, nums1Size, offset, i);
                offset++;
                nums1[i] = nums2[j];
                j++;
            }
        } else {
            nums1[i] = nums2[j];
            j++;
        }
    }
}

/* https://leetcode.cn/problems/minimum-size-subarray-sum/ */

int minSubArrayLen(int target, int *nums, int numsSize)
{
    if (nums == NULL) {
        return 0;
    }
    // 尺缩法
    int slow = 0, fast = 1, gap = 0, is_first_time = true;
    int sum = nums[slow];

    if (sum >= target) {
        return 1;
    }

    for (fast = 1; fast < numsSize; fast++) {
        sum += nums[fast];
        if (sum >= target) { // 2+3+1+2+4+3
            //printf("1_sum=%d\n", sum);
            for (; slow < fast + 1; slow++) {
                sum -= nums[slow];
                if (sum < target) {
                    sum += nums[slow];
                    if (is_first_time) {
                        gap = fast - slow + 1;
                        is_first_time = false;
                    }
                    if (fast - slow + 1 < gap) {
                        gap = fast - slow + 1;
                    }
                    //printf("2_sum=%d, gap=%d\n", sum, gap);
                    if (gap == 1) {
                        return 1;
                    }
                    break;
                }
            }
        }
    }

    return gap;
}

/* https://leetcode.cn/problems/move-zeroes/ */

void moveZeroes(int *nums, int numsSize)
{
    if (nums == NULL) {
        return;
    }
    int i, j = 0;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            j++;
        } else if (j != 0) {
            nums[i - j] = nums[i];
            nums[i] = 0;
        }
    }
}

/* https://leetcode.cn/problems/pascals-triangle/ */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
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
                ret[*returnSize][j] =
                    ret[*returnSize - 1][j - 1] + ret[*returnSize - 1][j];
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
int *getRow(int rowIndex, int *returnSize)
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

/* https://leetcode.cn/problems/find-pivot-index/ */

int pivotIndex(int *nums, int numsSize)
{
    int i;
    int sum = 0;
    int left = 0;

    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    for (i = 0; i < numsSize; i++) {
        if (left * 2 + nums[i] == sum) {
            return i;
        }
        left += nums[i];
    }
    return -1;
}

/* https://leetcode.cn/problems/plus-one/ */

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
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

/* https://leetcode.cn/problems/remove-duplicates-from-sorted-array/ */

int removeDuplicates(int *nums, int numsSize)
{
    int s = 0, f = 1;
    while (s < f && f < numsSize) {
        if (nums[s] != nums[f]) {
            s++;
        }
        f++;
        if (f - s > 1) {
            nums[s] = nums[f - 1];
        }
    }
    return s + 1;
}

/* https://leetcode.cn/problems/remove-element/ */

int removeElement(int *nums, int numsSize, int val)
{
    if (nums == NULL) {
        return 0;
    }
    int fast, slow;
    for (slow = 0, fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}

/* https://leetcode.cn/problems/rotate-image/ */

void rotate_image(int **matrix, int matrixSize, int *matrixColSize)
{
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

void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    // 水平翻转
    for (int i = 0; i < matrixSize / 2; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            swap(&matrix[i][j], &matrix[matrixSize - i - 1][j], sizeof(int));
        }
    }
    // 主对角线翻转
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(&matrix[i][j], &matrix[j][i], sizeof(int));
        }
    }
}

/* https://leetcode.cn/problems/search-insert-position/ */

int searchInsert(int *nums, int numsSize, int target)
{
    int i;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] >= target) {
            return i;
        }
    }
    return i;
}

/* https://leetcode.cn/problems/zero-matrix-lcci/ */

void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
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

/* https://leetcode.cn/problems/single-number/ */

int singleNumber(int *nums, int numsSize)
{
    int i, result = 0;
    for (i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

/* https://leetcode.cn/problems/3sum-closest/ */

int threeSumClosest(int *nums, int numsSize, int target)
{
    int sum = 0;
    int i;
    int left;
    int right;
    int closest = 0;
    int tmp;
    int flag = false;

    qsort(nums, numsSize, sizeof(int), cmp);
    PRINT_ARRAY(nums, numsSize, "%d ");

    for (i = 0; i < numsSize - 2; i++) {
        for (left = i + 1, right = numsSize - 1; left != right;) {
            sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                return sum;
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }

            if (!flag) {
                flag = true;
                tmp = abs(target - sum);
                closest = sum;
            } else if (tmp > abs(target - sum)) {
                tmp = abs(target - sum);
                closest = sum;
            }
        }
    }

    return closest;
}

/*
    升序
    -4 -1 1 2
    -5 -5 -4 0 0 3 3 4 5
    2 3 8 9 10
*/
void threeSumClosestTest(void)
{
    // int nums[] = {-1,2,1,-4};
    // int nums[] = {4,0,5,-5,3,3,0,-4,-5};
    // int nums[] = {1,1,1,0};
    int nums[] = { 2, 3, 8, 9, 10 };
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 16;

    int ans = threeSumClosest(nums, numsSize, target);

    printf("output: ans=%d\n", ans);
}

/* https://leetcode.cn/problems/3sum/ */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **threeSum(int *nums, int numsSize, int *returnSize,
               int **returnColumnSizes)
{
    bubble_sort(nums, numsSize);

    *returnSize = 0;
    short left = 0;
    short right = numsSize - 1;

    int **ret = (int **)malloc(sizeof(int *) * (numsSize + 1) * 6);
    *returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 6);
    ret[*returnSize] = malloc(sizeof(int) * 3);

    while (left + 1 < right) {
        int i = left + 1;
        int j = right;
        while (i < j) {
            if (nums[i] + nums[j] + nums[left] < 0) {
                i++;
            } else if (nums[i] + nums[j] + nums[left] > 0) {
                j--;
            } else {
                ret[*returnSize][0] = nums[left];
                ret[*returnSize][1] = nums[i];
                ret[*returnSize][2] = nums[j];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                ret[*returnSize] = malloc(sizeof(int) * 3);

                do {
                    if (nums[i] == nums[i + 1]) {
                        i++;
                    }
                } while (i < j);

                do {
                    if (nums[j] == nums[j - 1]) {
                        j--;
                    }
                } while (i < j);
            }
        }

        do {
            if (nums[left] == nums[left + 1]) {
                left++;
            }
        } while (left + 1 < right);
    }

    return ret;
}

/* https://leetcode.cn/problems/two-out-of-three/ */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_LEN 100

int *twoOutOfThree(int *nums1, int nums1Size, int *nums2, int nums2Size,
                   int *nums3, int nums3Size, int *returnSize)
{
    int mp[MAX_LEN + 1];
    memset(mp, 0, sizeof(int) * (MAX_LEN + 1));
    int i;
    for (i = 0; i < nums1Size; i++) {
        mp[nums1[i]] = 1;
    }
    for (i = 0; i < nums2Size; i++) {
        mp[nums2[i]] |= 2;
    }
    for (i = 0; i < nums3Size; i++) {
        mp[nums3[i]] |= 4;
    }
    int pos = 0;
    int *res = (int *)malloc(sizeof(int) * MAX_LEN);
    if (res == NULL) {
        return NULL;
    }
    memset(res, 0, sizeof(int) * MAX_LEN);
    for (i = 0; i <= MAX_LEN; i++) {
        if (mp[i] & (mp[i] - 1)) {
            res[pos] = i;
            pos++;
        }
    }
    *returnSize = pos;
    return res;
}

/* https://leetcode.cn/problems/two-sum/ */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    for (int i = 0; i < numsSize - 1; ++i) {
        for (int j = 0; j < numsSize - i - 1; ++j) {
            if (nums[i] + nums[j + i + 1] == target) {
                int *ret = (int *)malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j + i + 1;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

void twoSumTest(void)
{
    int nums[4] = { 2, 7, 11, 15 };
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize;

    int *ans = twoSum(nums, numsSize, target, &returnSize);

    printf("output: [%d,%d]\n", ans[0], ans[1]);
}

/* https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/ */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum2(int *numbers, int numbersSize, int target, int *returnSize)
{
    if (numbers == NULL || returnSize == NULL) {
        return NULL;
    }
    int *ans = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;

    int left = 0, right = numbersSize - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            ans[0] = left + 1;
            ans[1] = right + 1;
            return ans;
        } else if (sum > target) {
            right--;
        } else {
            left++;
        }
    }
    return NULL;
}
