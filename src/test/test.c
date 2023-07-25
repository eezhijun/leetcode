#include "internal.h"

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

void test(void)
{

    // swap_test();
    // sort_test();
    max_test();
}
