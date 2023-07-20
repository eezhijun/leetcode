#include "stdio.h"
#include "errno.h"

#define TEST_DEMO       0
#define LC_DEMO         1

#ifdef USER_DEMO
    #define MAIN_SELECTED_APP    USER_DEMO
#else
    #define MAIN_SELECTED_APP    LC_DEMO
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
