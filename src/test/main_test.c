#include "stdio.h"
#include "stdlib.h"
#include "utils.h"
#include "gnu/libc-version.h"

int g_m, g_n; // 表示定义该文件全局变量
extern int g_a, g_b; // 表示外部已经定义好的全局变量，这里是该文件对其声明，不是定义。

void main_test(void)
{
    printf("TEST ENTRY\n");
    printf("GNU libc version: %s\n", gnu_get_libc_version());

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
