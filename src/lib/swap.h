#ifndef _SWAP_H_
#define _SWAP_H_

#define SWAP(type, lhs, rhs) \
do \
{ \
    type temp = lhs; \
    lhs = rhs; \
    rhs = temp; \
} while(0)

void swap(void* lhs, void* rhs, size_t size);
void swap_by_temp(int* lhs, int *rhs);
void swap_by_sum(int* lhs, int* rhs);
void swap_by_xor(int *lhs, int *rhs);

#endif
