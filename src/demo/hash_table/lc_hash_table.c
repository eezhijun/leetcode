/**
 * @file lc_hash_table.c
 * @author hongzhijun (eehongzhijun@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-10-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "uthash.h"

/* https://leetcode.cn/problems/happy-number/ */
/* 编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

示例 1：

输入：n = 19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
示例 2：

输入：n = 2
输出：false
提示：

1 <= n <= 231 - 1 */
#if defined HASH_TABLE_isHappy
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} ht_t;

ht_t *ht = NULL;

ht_t *find(int key)
{
    ht_t *tmp;
    HASH_FIND_INT(ht, &key, tmp);
    return tmp;
}

ht_t *insert(int key)
{
    ht_t *it;
    HASH_FIND_INT(ht, &key, it);
    if (it == NULL) {
        it = (ht_t *)malloc(sizeof *it);
        it->key = key;
        it->val = 0;
        HASH_ADD_INT(ht, key, it);
    } else {
        it->val = 1;
    }
    return it;
}

void deelte_all(void)
{
    ht_t *it;
    ht_t *tmp;

    HASH_ITER(hh, ht, it, tmp)
    {
        printf("it->key=%d\n", it->key);
        HASH_DEL(ht, it); /* delete it */
        free(it); /* free it */
    }
}

void print_users(void)
{
    ht_t *it;

    for (it = ht; it != NULL; it = (ht_t *)(it->hh.next)) {
        printf("key:%d\n", it->key);
    }
}

bool isHappy(int n)
{
    int sum = 0;
    int m = 0;
    ht = NULL;
    insert(n);
    while (1) {
        while (n != 0) {
            m = n % 10;
            n /= 10;
            sum += pow(m, 2);
        }
        printf("sum=%d\n", sum);
        if (sum == 1) {
            return true;
        }
        n = sum;
        sum = 0;
        ht_t *it = insert(n);
        printf("it->val=%d\n", it->val);
        if (it->val) {
            return false;
        }
    }
    return 0;
}

void isHappyTest(void)
{
    int n = 13;
    printf("input:%d\n", n);
    printf("output:%s\n", (isHappy(n) == 1) ? "true" : "false");
    deelte_all();
}
#endif

void lc_hash_table_test(void)
{
    // isHappyTest();
}
