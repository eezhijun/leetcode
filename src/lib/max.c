#include "stdio.h"
#include "max.h"

// MAXT(int)
// MAXT(float)
// MAXT(double)

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a > b) ? b : a;
}

void max_test(void)
{
    int n1 = 0;
    int n2 = 0;

    scanf("%d%d", &n1, &n2);

    printf("max=%d\n", MAX(n1, n2));

}
