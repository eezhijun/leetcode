/**
 * @file main_lc.c
 * @author hongzhijun (eehongzhijun@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "stdio.h"

/* array */
extern void lc_array_easy_test(void);
extern void lc_array_medium_test(void);
extern void lc_array_diffcult_test(void);

/* string */
extern void lc_string_easy_test(void);
extern void lc_string_medium_test(void);
extern void lc_string_diffcult_test(void);

/* stack */
extern void lc_stack_easy_test(void);

/* queue */
extern void lc_queue_easy_test(void);

int main_lc(void)
{
    printf("LEETCODE ENTRY\n");

    /* array */
    lc_array_easy_test();
    lc_array_medium_test();
    lc_array_diffcult_test();

    /* string */
    lc_string_easy_test();
    lc_string_medium_test();
    lc_string_diffcult_test();

    /* stack */
    lc_stack_easy_test();

    /* queue */
    lc_queue_easy_test();

    return 0;
}
