/**
 * @file main_test.c
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
#include "string.h"
#include "stdbool.h"
#include "math.h"
#include "float.h"

#include "gnu/libc-version.h"


#include "utils.h"

extern void stack_test(void);
extern void queue_test(void);
extern int memory_layout_test(void);
extern int hash_table_test(void);

int g_m, g_n; // 表示定义该文件全局变量
extern int g_a, g_b; // 表示外部已经定义好的全局变量，这里是该文件对其声明，不是定义。

void extern_test(void)
{

    printf("EXTERN TEST\n");
    /* int g_x, g_y; 定义局部变量*/
    extern int g_x, g_y; // 声明外部全局变量，下面才可以使用
    printf("g_x=%d, g_y=%d\n", g_x, g_y);
}

// 定义全局变量g_x, g_y，但是上面main_test函数想使用全局变量必须使用extern进行声明才能引用
int g_x = 0;
int g_y = 1;
void test(void)
{
    printf("test, g_x=%d, g_y=%d\n", g_x, g_y);
}

/* string.h */
void memset_test(void)
{
    int arr[10];
    int len = 10;

    /* wrong */
    memset(arr, 0, len);
    PRINT_ARRAY(arr, len, "%d ");

    /* wrong */
    /*  预期初始化数组每个元素为1，
        实际确是这样0b 00000001 00000001 00000001 00000001
        如果想初始化数组元素要用循环语句来初始化 */
    memset(arr, 1, len * sizeof(int));
    PRINT_ARRAY(arr, len, "%d ");
    PRINT_ARRAY(arr, len, "%08x ");

    /* right */
    memset(arr, 0, len * sizeof(int));
    PRINT_ARRAY(arr, len, "%d ");

    for (int i = 0; i < len; i++) {
        arr[i] = 1;
    }
    PRINT_ARRAY(arr, len, "%d ");
}

void hex2dec_test(void)
{
    char hex[128] = {0};

    printf("please input hex:\n");
    scanf("%s", hex);

    // PRINT_ARRAY(hex, 128, "%d ");
    int ret = hex2dec(hex);

    printf("output:%d\n", ret);
}

void dec2hex_test(void)
{
    int dec;

    printf("please input dec:\n");
    scanf("%d", &dec);

    char *ret = dec2hex(dec);

    printf("output:%s\n", ret);
    free(ret);
}

void sprintf_test(void)
{
    char *s = (char *)malloc(sizeof(char) * (4 + 1));

    sprintf(s, "%d", 1234);

    PRINT_ARRAY(s, 5, "%d ");
}

void limits_test(void)
{
    /* limits.h */
    /* bit */
    printf("%s=\t+%d\n", STR(CHAR_BIT), CHAR_BIT);

    /* char */
    printf("%s=\t%d\n", STR(SCHAR_MIN), SCHAR_MIN);
    printf("%s=\t+%u\n", STR(UCHAR_MAX), UCHAR_MAX);
    printf("%s=\t%d\n", STR(CHAR_MIN), CHAR_MIN);
    printf("%s=\t+%d\n", STR(CHAR_MAX), CHAR_MAX);

    /* short */
    printf("%s=\t%d\n", STR(SHRT_MIN), SHRT_MIN);
    printf("%s=\t+%d\n", STR(SHRT_MAX), SHRT_MAX);
    printf("%s=\t+%u\n", STR(USHRT_MAX), USHRT_MAX);

    /* int */
    printf("%s=\t%d\n", STR(INT_MIN), INT_MIN);
    printf("%s=\t+%d\n", STR(INT_MAX), INT_MAX);
    printf("%s=\t+%u\n", STR(UINT_MAX), UINT_MAX);

    /* long */
    printf("%s=\t%ld\n", STR(LONG_MIN), LONG_MIN);
    printf("%s=\t+%ld\n", STR(LONG_MAX), LONG_MAX);
    printf("%s=\t+%lu\n", STR(ULONG_MAX), ULONG_MAX);

    /* long long */
    printf("%s=\t%lld\n", STR(LLONG_MIN), LLONG_MIN);
    printf("%s=\t+%lld\n", STR(LLONG_MAX), LLONG_MAX);
    printf("%s=\t+%llu\n", STR(ULLONG_MAX), ULLONG_MAX);

    /* float.h */
    /* float double */

    printf("%s=\t+%d\n", STR(FLT_DIG), FLT_DIG);
    printf("%s=\t+%d\n", STR(DBL_DIG), DBL_DIG);
    printf("%s=\t+%d\n", STR(LDBL_DIG), LDBL_DIG);

    printf("%s=\t+%f\n", STR(FLT_MAX), FLT_MAX);
    printf("%s=\t+%f\n", STR(DBL_MAX), DBL_MAX);
    printf("%s=\t+%Lf\n", STR(LDBL_MAX), LDBL_MAX);

    printf("%s=\t+%f\n", STR(FLT_MIN), FLT_MIN);
    printf("%s=\t+%f\n", STR(DBL_MIN), DBL_MIN);
    printf("%s=\t+%f\n", STR(DBL_MIN), DBL_MIN);
}

typedef struct {
    int a;
    int b;
} testa_t;

void sizeof_test(void)
{
    char *s;
    char *t[4];
    int *a;
    int arr[10];
    testa_t *t1;

    printf("%s=%d\n", STR(sizeof s), sizeof s);
    printf("%s=%d\n", STR(sizeof *s), sizeof *s);
    printf("%s=%d\n", STR(sizeof(char)), sizeof(char));
    printf("%s=%d\n", STR(sizeof(char *)), sizeof(char *));

    printf("%s=%d\n", STR(sizeof t), sizeof t);
    printf("%s=%d\n", STR(sizeof *t), sizeof *t);

    printf("%s=%d\n", STR(sizeof a), sizeof a);
    printf("%s=%d\n", STR(sizeof *a), sizeof *a);
    printf("%s=%d\n", STR(sizeof(int)), sizeof(int));
    printf("%s=%d\n", STR(sizeof(int *)), sizeof(int *));

    printf("%s=%d\n", STR(sizeof arr), sizeof arr);
    printf("%s=%d\n", STR(sizeof(arr)), sizeof(arr));

    printf("%s=%d\n", STR(sizeof t1), sizeof t1);
    printf("%s=%d\n", STR(sizeof *t1), sizeof *t1);
    printf("%s=%d\n", STR(sizeof(testa_t)), sizeof(testa_t));

}

void scanf_gets_fgets_test(void)
{
    // char s[128];

    // printf("please input string s:\n");
    // scanf("%s", s);

    // printf("output:\n");
    // printf("%s\n", s);

    // char t[128];
    // printf("please input string t:\n");
    // gets(t);

    // printf("output:\n");
    // printf("%s\n", t);

    char k[128];
    printf("please input string k:\n");
    fgets(k, 128, stdin);

    printf("output:\n");
    printf("%s\n", k);
}

void main_test(void)
{
    printf("TEST ENTRY\n");
    printf("GNU libc version: %s %s\n", gnu_get_libc_version(), ENVIRONMENT);
    // memory_layout_test();
    // memset_test();

    // stack_test();
    // queue_test();

    // hex2dec_test();
    // dec2hex_test();
    // sprintf_test();
    // limits_test();
    // sizeof_test();
    // hash_table_test();
    // scanf_gets_fgets_test();

}
