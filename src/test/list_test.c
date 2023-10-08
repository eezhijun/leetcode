/**
 * @file list_test.c
 * @author hongzhijun (eehongzhijun@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-10-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct node {
    int data;
    struct node *next;
};

// 创建一个新节点
struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// 在链表头部插入节点
void insert_node_at_head(struct node **head, int data)
{
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// 在链表末尾插入节点
void append_node(struct node **head, int data)
{
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// 删除指定值的节点
void delete_node(struct node **head, int data)
{
    struct node *current = *head;
    struct node *prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("节点 %d 未找到\n", data);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// 打印链表内容
void print_list(struct node *head)
{
    struct node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 主函数
int list_test(void)
{
    struct node *head = NULL; // 初始化一个空链表

    // 在链表头部插入节点
    insert_node_at_head(&head, 1);
    insert_node_at_head(&head, 2);
    insert_node_at_head(&head, 3);

    // 在链表末尾插入节点
    append_node(&head, 4);
    append_node(&head, 5);

    // 打印链表内容
    printf("链表内容：\n");
    print_list(head);

    // 删除节点
    delete_node(&head, 3);
    delete_node(&head, 6);

    // 打印链表内容
    printf("删除后的链表内容：\n");
    print_list(head);

    return 0;
}
