#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include "tlsf.h"

#define TEST_BUFF_SIZE 100
#define MEM_RESERVED_SIZE 32U * 1024U       /* 32KB */

static tlsf_t s_tlsf = NULL;

void init_memory(void)
{
    if (s_tlsf == NULL)
    {
        void *buffer = malloc(MEM_RESERVED_SIZE);
        s_tlsf = tlsf_create_with_pool(buffer, MEM_RESERVED_SIZE);
    }
}

void *get_memory(size_t size)
{
    if (s_tlsf == NULL)
    {
        init_memory();
    }

    void *ptr_mem = tlsf_malloc(s_tlsf, size);
    while (ptr_mem == NULL)
    {
        void *add_pool = malloc(MEM_RESERVED_SIZE); // malloc 32KB
        if (add_pool == NULL)
        {
            printf("malloc fail line=%d\n", __LINE__);
            return NULL;
        }
        tlsf_add_pool(s_tlsf, add_pool, MEM_RESERVED_SIZE);
        ptr_mem = tlsf_malloc(s_tlsf, size);
    }
    return ptr_mem;
}

void free_memory(void *p)
{
    tlsf_free(s_tlsf, p);
}

void sort_test(void)
{
    int arr[] = {1, 3, 7, 10, 2, 3, 5, 8};
    int len = sizeof(arr) / sizeof(int);

    print_array(arr, len);
    bubble_sort(arr, len);

    printf("after sort\n");
    print_array(arr, len);

}

void max_test(void)
{
    int n1 = 0;
    int n2 = 0;

    scanf("%d%d", &n1, &n2);

    printf("max=%d\n", MAX(n1, n2));

}

typedef struct {
  char c;
  double x;
  double y;
} coordinate_t;

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

void test(void)
{

    // swap_test();
    // sort_test();
    max_test();
}
