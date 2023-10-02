#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义键值对结构
struct key_value {
    char *key;
    int value;
    struct key_value *next;
};

// 定义哈希表结构
struct hash_table {
    struct key_value **table;
    size_t size;
};

// 创建一个新的哈希表
struct hash_table *create_hash_table(size_t size)
{
    struct hash_table *hash_table =
        (struct hash_table *)malloc(sizeof(struct hash_table));
    if (!hash_table) {
        perror("Failed to allocate memory for the hash table");
        exit(EXIT_FAILURE);
    }

    hash_table->size = size;
    hash_table->table =
        (struct key_value **)malloc(sizeof(struct key_value *) * size);
    if (!hash_table->table) {
        perror("Failed to allocate memory for the hash table array");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; i++) {
        hash_table->table[i] = NULL;
    }

    return hash_table;
}

// 哈希函数，简单地将字符串的字符相加，并取余哈希表大小
size_t hash(const char *key, size_t size)
{
    size_t hash_value = 0;
    while (*key) {
        hash_value += *key;
        key++;
    }
    return hash_value % size;
}

// 插入键值对到哈希表
void insert(struct hash_table *hash_table, const char *key, int value)
{
    size_t index = hash(key, hash_table->size);

    struct key_value *new_key_value =
        (struct key_value *)malloc(sizeof(struct key_value));
    if (!new_key_value) {
        perror("Failed to allocate memory for a key-value pair");
        exit(EXIT_FAILURE);
    }

    new_key_value->key = strdup(key);
    if (!new_key_value->key) {
        perror("Failed to duplicate key string");
        exit(EXIT_FAILURE);
    }

    new_key_value->value = value;
    new_key_value->next = hash_table->table[index];
    hash_table->table[index] = new_key_value;
}

// 查找键对应的值
int find(struct hash_table *hash_table, const char *key)
{
    size_t index = hash(key, hash_table->size);
    struct key_value *current = hash_table->table[index];

    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    // 键未找到
    return -1;
}

// 从哈希表中删除键值对
void delete(struct hash_table *hash_table, const char *key)
{
    size_t index = hash(key, hash_table->size);
    struct key_value *current = hash_table->table[index];
    struct key_value *prev = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                hash_table->table[index] = current->next;
            }

            free(current->key);
            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
}

// 释放哈希表内存
void destroy_hash_table(struct hash_table *hash_table)
{
    for (size_t i = 0; i < hash_table->size; i++) {
        struct key_value *current = hash_table->table[i];
        while (current) {
            struct key_value *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(hash_table->table);
    free(hash_table);
}

int hash_table_test1(void)
{
    struct hash_table *hash_table = create_hash_table(100);

    insert(hash_table, "apple", 5);
    insert(hash_table, "banana", 10);
    insert(hash_table, "cherry", 15);

    printf("apple: %d\n", find(hash_table, "apple")); // 输出 5
    printf("banana: %d\n", find(hash_table, "banana")); // 输出 10

    delete (hash_table, "banana");
    printf("banana: %d\n", find(hash_table, "banana")); // 输出 -1，因为已删除

    destroy_hash_table(hash_table);

    return 0;
}
