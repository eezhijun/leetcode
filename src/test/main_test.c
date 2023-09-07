#include "stdio.h"
#include "stdlib.h"
#include "utils.h"
#include "gnu/libc-version.h"

void main_test(void)
{
    printf("TEST ENTRY\n");
    printf("GNU libc version: %s\n", gnu_get_libc_version());
}
