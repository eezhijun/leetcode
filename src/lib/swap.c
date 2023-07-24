#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "swap.h"

typedef struct {
  char c;
  double x;
  double y;
} coordinate_t;

void swap(void* lhs, void* rhs, size_t size)
{
    if (lhs == NULL || rhs == NULL || size == 0)
    {
        return;
    }
    void *t = malloc(size);
    memcpy(t, lhs, size);
    memcpy(lhs, rhs, size);
    memcpy(rhs, t, size);
    free(t);
}

void swap_by_temp(int* lhs, int *rhs)
{
    if (lhs == NULL || rhs == NULL)
    {
        return;
    }
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

void swap_by_sum(int* lhs, int* rhs)
{
    if (lhs == NULL || rhs == NULL)
    {
        return;
    }
    *lhs = *lhs + *rhs;
    *rhs = *lhs - *rhs;
    *lhs = *lhs - *rhs;
}

void swap_by_xor(int *lhs, int *rhs)
{
    if (lhs == NULL || rhs == NULL)
    {
        return;
    }
    *lhs = *lhs ^ *rhs;
    *rhs = *lhs ^ *rhs;
    *lhs = *lhs ^ *rhs;
}

void swap_test(void)
{
    int a = 0;
    int b = 0;
    float c = 0;
    float d = 0;
    coordinate_t pos1;
    coordinate_t pos2;

    scanf("%d%d", &a, &b);
    scanf("%f%f", &c, &d);
    scanf(" %c %lf%lf", &(pos1.c), &(pos1.x), &(pos1.y));
    scanf(" %c %lf%lf", &(pos2.c), &(pos2.x), &(pos2.y));

    printf("before swap: a=%d, b=%d\n", a, b);
    printf("before swap: c=%f, d=%f\n", c, d);
    printf("before swap: pos1.c=%c, pos1.x=%lf, pos1.y=%lf\n", pos1.c, pos1.x, pos1.y);
    printf("before swap: pos2.c=%c, pos2.x=%lf, pos2.y=%lf\n", pos2.c, pos2.x, pos2.y);

    swap(&a, &b, sizeof(int));
    swap(&c, &d, sizeof(float));
    swap(&pos1, &pos2, sizeof(coordinate_t));
    // SWAP(int, a, b);
    // // swap_by_sum(&a, &b);
    // // swap_by_xor(&a, &b);

    printf("after swap: a=%d, b=%d\n", a, b);
    printf("after swap: a=%f, b=%f\n", c, d);
    printf("after swap: pos1.c=%c, pos1.x=%lf, pos1.y=%lf\n", pos1.c, pos1.x, pos1.y);
    printf("after swap: pos2.c=%c, pos2.x=%lf, pos2.y=%lf\n", pos2.c, pos2.x, pos2.y);
}
