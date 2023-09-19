/**
 * @file main.c
 * @author eehongzhijun (eehongzhijun@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "stdio.h"
#include "errno.h"


#if defined(LC_DEMO)
#define MAIN_SELECTED_APP LC_DEMO
#elif defined(TEST_DEMO)
#define MAIN_SELECTED_APP TEST_DEMO
#endif

extern int main_lc(void);
extern int main_test(void);


int main(void)
{
#if (MAIN_SELECTED_APP == TEST_DEMO)
    main_test();
#elif (MAIN_SELECTED_APP == LC_DEMO)
    main_lc();
#else
    #error "The selected demo is not valid"
#endif
    return 0;
}
