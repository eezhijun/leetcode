#include "stdio.h"
#include "errno.h"

#define TEST_DEMO 0
#define P_DEMO 1

#ifndef USER_DMEO
    #define MAIN_SELECTED_APP    P_DEMO
#else
    #define MAIN_SELECTED_APP    TEST_DEMO
#endif

extern int main_p(void);


int main(void)
{
#if (MAIN_SELECTED_APP == TEST_DEMO)
#elif (MAIN_SELECTED_APP == P_DEMO)
    main_p();
#else
    #error "The selected demo is not valid"
#endif
    return 0;
}
