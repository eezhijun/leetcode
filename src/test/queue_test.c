/**
 * @file queue_test.c
 * @author eehongzhijun (eehongzhijun@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

/* queue
    |       | front
    |       |
    |       |
    |       | rear
*/

#define QUEUE_SIZE 10
typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
} queue_t;

void queue_init(queue_t *q)
{
    memset(q->data, 0, sizeof(int) * QUEUE_SIZE);
    q->front = -1;
    q->rear = -1;
}

bool queue_is_empty(queue_t *q)
{
    return (q->front == -1);
}

bool queue_is_full(queue_t *q)
{
    return (q->rear == QUEUE_SIZE - 1);
}

void queue_enqueue(queue_t *q, int val)
{
    if (queue_is_full(q)) {
        printf("queue is full\n");
        return;
    }

    if (queue_is_empty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = val;
}

int queue_dequeue(queue_t *q)
{
    int val;
    if (queue_is_empty(q)) {
        printf("queue is empty\n");
        return -1;
    }
    val = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return val;
}

void queue_display(queue_t *q)
{
    if (queue_is_empty(q)) {
        printf("queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

void queue_test(void)
{
    queue_t q;

    queue_init(&q);

    queue_enqueue(&q, 1);
    queue_enqueue(&q, 2);
    queue_enqueue(&q, 3);
    queue_enqueue(&q, 4);
    queue_enqueue(&q, 5);

    queue_display(&q);

    printf("dequeue: %d\n", queue_dequeue(&q));
    printf("dequeue: %d\n", queue_dequeue(&q));

    queue_display(&q);
}
