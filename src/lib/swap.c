#include "stdio.h"

void swap_char(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

void swap_int(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void swap_char2(char *a, char *b)
{
    if (a == NULL || b == NULL) {
        return;
    }
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
