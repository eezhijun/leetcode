/**
 * @file test.c
 * @author hongzhijun (eehongzhijun@outlook.com)
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
#include "ctype.h"

#include "gnu/libc-version.h"
#include "pthread.h"

#include "utils.h"
#include "test.h"

int g_m, g_n; // 表示定义该文件全局变量
extern int g_a,
    g_b; // 表示外部已经定义好的全局变量，这里是该文件对其声明，不是定义。

void test_extern(void)
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
void test_memset(void)
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

void test_hex2dec(void)
{
    char hex[128] = {0};

    printf("please input hex:\n");
    scanf("%s", hex);

    // PRINT_ARRAY(hex, 128, "%d ");
    int ret = hex2dec(hex);

    printf("output:%d\n", ret);
}

void test_dec2hex(void)
{
    int dec;

    printf("please input dec:\n");
    scanf("%d", &dec);

    char *ret = dec2hex(dec);

    printf("output:%s\n", ret);
    free(ret);
}

void test_sprintf(void)
{
    int idx = 0;
    int size = 12;
    char *s = (char *)malloc(sizeof(char) * size);
    memset(s, 0, sizeof(char) * size);

    idx += sprintf(s + idx, "%d", 123);
    PRINT_ARRAY(s, size, "%d ");

    idx += sprintf(s + idx, "%d", -1234);
    PRINT_ARRAY(s, size, "%d ");

    idx += sprintf(s + idx, "%s", "-->");
    PRINT_ARRAY(s, size, "%c ");
}

void test_limits(void)
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

void test_sizeof(void)
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

void test_scanf_gets_fgets(void)
{
    char s[128];
    size_t len = 0;

#define FGETS_TEST
#if defined(SCANF_TEST)
    printf("please input string s by scanf:\n");
    scanf("%s", s);
    len = strlen(s);
#elif defined(GETS_TEST)
    printf("please input string s by gets:\n");
    gets(s);
    len = strlen(s);
#elif defined(FGETS_TEST)
    printf("please input string s by fgets:\n");
    fgets(s, 128, stdin);
    len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
#endif

    printf("output:\n");
    printf("%s\n", s);
    PRINT_ARRAY(s, len, "%d ");
}

void test_toupper_tolower(void)
{
    char table[] = "asdfghjkl";
    size_t len = strlen(table);

    printf("init:%s\n", table);
    printf("toupper:\n");
    for (int i = 0; i < len; i++) {
        table[i] = toupper(table[i]);
    }
    printf("%s\n", table);

    printf("tolower:\n");
    for (int i = 0; i < len; i++) {
        table[i] = tolower(table[i]);
    }
    printf("%s\n", table);
}

void array_process3(int (*a)[5], int row, int col)
{
    PRINT_ARRAY2D(a, row, col, "%d ");
}

void array_process2(int **a, int row, int col)
{
    PRINT_ARRAY2D(a, row, col, "%d ");
}

void array_process(int a[][5], int row, int col)
{
    PRINT_ARRAY2D(a, row, col, "%d ");
}

/*
            实参            所匹配的形参
数组的数组    char a[3][5]   char (*)[5]  数组指针
指针数组      char *a[5]     char **a     指针的指针
数组指针      char (*a)[5]   char (*)[5]  数组指针
指针的指针     char **a      char **a     指针的指针
*/
void array_test(void)
{
    /* 注意二级指针和二维数组不要混用 */
    int arr[3][5] = {{0, 1, 1, 0, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};
    int size = XARRAY_SIZE(arr);
    int row_size = ROW_SIZE(arr);
    int col_size = COL_SIZE(arr);

    printf("arr test\n");
    printf("total_size=%d\n",
           sizeof(arr)); // 3x5x4 计算整个数组占大小，以字节为单位
    printf("size=%d\n", size); // 3x5 计算二维数组元素个数
    printf("row_size=%d\n", row_size); // 3 计算二维数组行数
    printf("col_size=%d\n", col_size); // 5 计算二维数组列数
    printf("ptr arr=%p, ptr arr[0]=%p, ptr arr[0][0]=%p\n", arr, arr[0],
           &arr[0][0]);
    array_process(arr, row_size, col_size);
    printf("print arr element address\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%p ", &arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("arr2 test\n");
    int row = 3;
    int col = 5;
    int **arr2 = (int **)malloc(sizeof(int *) * row);
    if (!arr2) {
        printf("arr2 malloc failed\n");
        exit(-1);
    }
    memset(arr2, 0, sizeof(int *) * row);
    for (int i = 0; i < row; i++) {
        arr2[i] = (int *)malloc(sizeof(int) * col);
        if (!arr2[i]) {
            printf("arr2[%d] malloc failed\n", i);
            exit(-1);
        }
        memset(arr2[i], 0, sizeof(int) * col);
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr2[i][j] = (i + 1) * j;
        }
    }
    array_process2(arr2, row, col);
    printf("print arr2 element address\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%p ", &arr2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    /*
    如下使用会发生段错误，首先arr是一个二维数组，内存是连续的，但上面arr2申请内存不是连续的，
    另外arr2是一个指针的指针类型，它是一维的，而arr一个是数组指针类型，它是二维的。
    memcpy(arr2, arr, sizeof(int) * 3 * 5);
    array_process2(arr2, row, col);
*/

    printf("arr3 test\n");
    int(*arr4)[5] = NULL;
    arr4 = arr;
    array_process3(arr4, 3, 5);

    printf("arr4, test\n");
    int(*arr5)[5] = (int(*)[5])malloc(sizeof(int) * 3 * 5);
    memset(arr5, 0, sizeof(int) * 3 * 5);
    array_process(arr5, 3, 5);
    // arr5 = arr;
    memcpy(arr5, arr, sizeof(int) * 3 * 5);
    array_process(arr5, 3, 5);

    printf("arr5, test\n");
    int *arr6[3] = {0};
    for (int i = 0; i < 3; i++) {
        arr6[i] = arr[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%p ", &arr6[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    array_process2(arr6, 3, 5);
    printf("----------------------\n");

    int a[5] = {1, 2, 3, 4, 5};
    int a_size = ARRAY_SIZE(a);
    PRINT_ARRAY(a, a_size, "%d ");
    printf("\n");

    int *b = (int *)malloc(sizeof(int) * 5);
    int b_size = 5;
    PRINT_ARRAY(b, b_size, "%d ");
    printf("\n");

    memcpy(b, a, sizeof(int) * 5);
    PRINT_ARRAY(b, b_size, "%d ");
    printf("\n");
    printf("----------------------\n");
}

void test_bin(void)
{
    int n = 10;
    printf_bin(n);
}

void test_bit(void)
{
    uint32_t n = 0x0A;
    printf("0x%X=\n", n);
    printf_bin(n);

    n = bit_set(n, 2);
    printf("bit_set(0x%X, 2)=\n", n);
    printf_bin(n);

    n = bit_clear(n, 2);
    printf("bit_clear(0x%X, 2)=\n", n);
    printf_bin(n);

    n = bit_toggle(n, 2);
    printf("bit_toggle(0x%X, 2)=\n", n);
    printf_bin(n);

    bool ret = bit_check(n, 0);
    printf("bit_check(0x%X, 0)=%s\n", n, ret ? "true" : "false");
    printf_bin(n);

    n = bit_set_to(n, 2, 0);
    printf("bit_set_to(0x%X, 2, 0)\n", n);
    printf_bin(n);
}

int main(int argc, char *argv[])
{
    printf("TEST ENTRY\n");
    printf("GNU libc version: %s %s\n", gnu_get_libc_version(), ENVIRONMENT);

    // array_test();

    // test_traffic_light();
    // test_light_switch();
    // test_door();
    // test_state();

    // test_bin();
    // test_bit();
    // test_bit();

    // test_hash_table();
}
