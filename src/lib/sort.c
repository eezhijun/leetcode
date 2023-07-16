#include "stdio.h"
#include "stdbool.h"


void bubbleSort (int arr[], int len)
{
    int i, j,temp;
    _Bool exchanged = true;

    for (i = 0; exchanged && i < len - 1; i++)
    {
        exchanged = false;
        for (j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                exchanged = true;
            }
        }
    }
}

int cmp(const void* pa, const void* pb)
{
    int a = *(int*)pa;
    int b = *(int*)pb;
    return a - b;
}
