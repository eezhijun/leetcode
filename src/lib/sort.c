#include "stdio.h"
#include "stdbool.h"

void print_array(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* https://zh.wikipedia.org/zh-cn/%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F */
void bubble_sort(int arr[], int len)
{
    int i, j,temp;
    bool exchanged = true;

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

void sort_test(void)
{
    int arr[] = {1, 3, 7, 10, 2, 3, 5, 8};
    int len = sizeof(arr) / sizeof(int);

    print_array(arr, len);
    bubble_sort(arr, len);

    printf("after sort\n");
    print_array(arr, len);

}
