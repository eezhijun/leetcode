#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

/* stack */
/*
    |       |
    |       |
    |       |
    |       |
    |______|
*/
#define STACK_SIZE 10
typedef struct {
    int data[STACK_SIZE];
    int top;
} stack_t;

void stack_init(stack_t *stack)
{
    memset(stack->data, 0, sizeof(int) * STACK_SIZE);
    stack->top = 0;
}

bool stack_is_full(stack_t *stack)
{
    return (stack->top == STACK_SIZE - 1);
}

bool stack_is_empty(stack_t *stack)
{
    return (stack->top == 0);
}

void stack_push(stack_t *stack, int val)
{
    if (stack_is_full(stack)) {
        printf("stack is full\n");
        return;
    }
    stack->data[stack->top] = val;
    stack->top++;
}

int stack_pop(stack_t *stack)
{
    if (stack_is_empty(stack)) {
        printf("stack is empty\n");
        return -1;
    }

    int val = stack->data[stack->top - 1];
    stack->top--;
    return val;
}

int stack_top(stack_t *stack)
{
    if (stack_is_empty(stack)) {
        printf("stack is empty\n");
        return -1;
    }
    return stack->data[stack->top - 1];
}

void stack_test(void)
{
    stack_t stack;

    stack_init(&stack);

    printf("stack push\n");
    stack_push(&stack, 1);
    stack_push(&stack, 2);
    stack_push(&stack, 3);
    stack_push(&stack, 4);
    stack_push(&stack, 5);

    printf("stack top element is %d\n", stack_top(&stack));

    while (!stack_is_empty(&stack)) {
        printf("stack pop %d\n", stack_pop(&stack));
    }
}
