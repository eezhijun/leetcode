#include <stdio.h>
#include "calc.h"

/*
-I 指定保护头文件路径
-L 指定库链接路径
-l 指定库名称
gcc src/mian.c -I include/ -L lib/ -l calc -o ./bin/main
*/

int main(void)
{
    int m, n;

    printf("MIAN ENTRY\n");
    printf("please input m and n:\n");
    scanf("%d %d", &m, &n);

    printf("%d+%d=%d\n", m, n, add(m, n));
    printf("%d-%d=%d\n", m, n, sub(m, n));
    printf("%dx%d=%d\n", m, n, mul(m, n));
    printf("%d/%d=%d\n", m, n, div(m, n));

    return 0;
}
